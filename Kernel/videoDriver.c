#include "videoDriver.h"
#include "font.h"
#include <stdint.h>
#define charWidth 8
#define charHeight 16

struct modeInfoBlock
{
    uint16_t modeAttributes;
    uint8_t winAAttributes;
    uint8_t winBAttributes;
    uint16_t winGranularity;
    uint16_t winSize;
    uint16_t winSegmentA;
    uint16_t winSegmentB;
    uint32_t winRealFctPtr;
    uint16_t pitch; // Bytes per ScanLine.

    uint16_t xResolution;
    uint16_t yResolution;
    uint8_t xCharSize;
    uint8_t yCharSize;
    uint8_t numberOfPlanes;
    uint8_t bitsPerPixel;
    uint8_t numberOfBanks;
    uint8_t memoryModel;
    uint8_t bankSize;
    uint8_t numberOfImagePages;
    uint8_t reservedPage;

    uint8_t redMaskSize;
    uint8_t redMaskPosition;
    uint8_t greenMaskSize;
    uint8_t greenMaskPosition;
    uint8_t blueMaskSize;
    uint8_t blueMaskPosition;
    uint8_t reservedMaskSize;
    uint8_t reservedMaskPosition;
    uint8_t directColorAttributes;

    uint32_t physBasePtr;  // Your LFB (Linear Framebuffer) address.
    uint32_t offScreenMemOffset;
    uint16_t offScreenMemSize;
} __attribute__((packed));

//The _attribute_ modifiers are needed to make gcc pack the structure into
//the standard VESA layout, rather than adding pad bytes between some of the
//fields like it would normally do.
//http://www.delorie.com/djgpp/doc/ug/graphics/vesa.html

modeInfoVBE vbe = (modeInfoVBE)0x5C00;
unsigned int currentX = 0;
unsigned int currentY = 0;
colour toDelete = {0, 0, 0};									// color NEGRO --> lo usamos para borrar

void drawAPixelWithColour(unsigned int x, unsigned int y, colour col)
{
    char * video = (char *) (uint64_t)(vbe->physBasePtr + vbe->pitch * currentY + currentX * (int)(vbe->bitsPerPixel/8));
    video[0] = col.blue;				// un pixel ocupa 3 bytes, en cada uno le asignamos un color primario para pintarlo
    video[1] = col.green;
    video[2] = col.red;
}

int coordanteOutOfBounds(unsigned int x, unsigned int y)
{
		return x>=0 && x<=vbe->xResolution && y>=0 && y<=vbe->yResolution;
}

void drawChar (const char c, colour col)
{
		refreshCoordenates();
		if (c < 31)						// entonces no es un caracter del font.c
		{
			if ( c == '\n')
			{
				enter();				// me muevo a una nueva linea
			}
			if (c == 8 )			// entonces quiere borrar el ultimo caracter
			{
				backSpace();
			}
		}
		else							// tengo un caracter del font.c
		{
				char * pixelMap = charMap((int)c);
				char pixel;
				for (int j=0; j<charHeight; j++)			// primero itero en j por como esta hecho el font
				{
					pixel = pixelMap[j];
					for (int i=0; i<charWidth; i++)
					{
						pixel >>= 8-i;								// itero por los caracteres
						if (pixel % 2 == 0)							// pixel = '_' --> no tengo que pintar
						{
							drawAPixelWithColour(currentX + i, currentY + j, toDelete);
						}
						else													// pixel = 'X'
						{
							drawAPixelWithColour(currentX + i, currentY + j, col);
						}
					}
				}
				currentX += charWidth;
		}
}

void drawString(char * string, colour c)
{
	int n = length(string);
	for (int i=0; i<n; i++)
	{
		drawChar(string[i], c);
	}
}

int length (char * string)
{
	int contador = 0;
	while (*string != '\n')
	{
		contador++;
		string++;
	}
	return contador;
}

void enter()
{
	currentX = 0;
	currentY += charHeight;
	if (currentY >= vbe->yResolution)
	{
		currentY -= charHeight;
		scroll();
	}
}

void backSpace()
{
	currentX -= charWidth;
	if (currentX < 0)
	{
		currentY -= charHeight;
		if (currentY < 0)
		{
			currentY = 0;
			currentX = 0;
		}
		else
		{
			currentX = vbe->xResolution - charWidth;
		}
	}
	clearCoordenate(currentX, currentY);					// "limpio" el lugar donde estan parados X e Y
}

void refreshCoordenates()
{
		if (currentX >= vbe->xResolution)
		{
			currentX = 0;
			currentY += charHeight;
		}

		if (currentY >= vbe->yResolution)
		{
			currentY -= charHeight;
			scroll();
		}
}

void clearCoordenate(unsigned int x, unsigned int y)
{
	for (int i = 0; i < charWidth; i++)
	{
		for (int j = 0; j < charHeight; j++)
		{
			drawAPixelWithColour(x+i, y+j, toDelete);			// no puedo usar drawChar porque esta seteado para que dibuje a partir de x e y --> pinto píxeles
		}
	}
}

void scroll ()
{
	colour col;
	char * pixelAddress;
	for (int i=0; i<vbe->xResolution; i++)
	{
		for (int j=charHeight; j<vbe->yResolution; j++)				// arranca desde charHeight porque copiamos la pantalla desde esa nueva linea
		{
			pixelAddress = (char *) (uint64_t)(vbe->physBasePtr + vbe->pitch * currentY + currentX * (int)(vbe->bitsPerPixel/8));
	    col.blue = pixelAddress[0];
			col.green = pixelAddress[1];
			col.red = pixelAddress[2];
			drawAPixelWithColour(i, j-charHeight, col);		// repintamos los pixeles de toda la pantalla
		}
	}
	int j = vbe->yResolution - charHeight;					// la ultima linea la dejamos libre
	for (int i=0; i < vbe->xResolution; i++)
	{
		clearCoordenate(i, j);
	}
}

void newWindow ()
{
	for (int i=0; i<vbe->xResolution; i++)
	{
		for (int j=0; j<vbe->yResolution; j++)
		{
			drawAPixelWithColour(i, j, toDelete);
		}
	}
}

void paintWindow(colour col)
{
	for (int i=0; i<vbe->xResolution; i++)
	{
		for (int j=0; j<vbe->yResolution; j++)
		{
			drawAPixelWithColour(i, j, col);
		}
	}
}

// -------------- VERSION PILO ---------------------------------------

// typedef struct __attribute__((packed)) {
// 	uint16_t attributes;		// deprecated, only bit 7 should be of interest to you, and it indicates the mode supports a linear frame buffer.
// 	uint8_t window_a;			// deprecated
// 	uint8_t window_b;			// deprecated
// 	uint16_t granularity;		// deprecated; used while calculating bank numbers
// 	uint16_t window_size;
// 	uint16_t segment_a;
// 	uint16_t segment_b;
// 	uint32_t win_func_ptr;		// deprecated; used to switch banks from protected mode without returning to real mode
// 	uint16_t pitch;			// number of bytes per horizontal line
// 	uint16_t width;			// width in pixels
// 	uint16_t height;			// height in pixels
// 	uint8_t w_char;			// unused...
// 	uint8_t y_char;			// ...
// 	uint8_t planes;
// 	uint8_t bpp;			// bits per pixel in this mode
// 	uint8_t banks;			// deprecated; total number of banks in this mode
// 	uint8_t memory_model;
// 	uint8_t bank_size;		// deprecated; size of a bank, almost always 64 KB but may be 16 KB...
// 	uint8_t image_pages;
// 	uint8_t reserved0;
//
// 	uint8_t red_mask;
// 	uint8_t red_position;
// 	uint8_t green_mask;
// 	uint8_t green_position;
// 	uint8_t blue_mask;
// 	uint8_t blue_position;
// 	uint8_t reserved_mask;
// 	uint8_t reserved_position;
// 	uint8_t direct_color_attributes;
//
// 	uint32_t framebuffer;		// physical address of the linear frame buffer; write here to draw to the screen
// 	uint32_t off_screen_mem_off;
// 	uint16_t off_screen_mem_size;	// size of memory in the framebuffer but not being displayed on the screen
// 	uint8_t reserved1[206];
// } vbe_mode_info_structure;
//
//
// vbe_mode_info_structure * vbe = (vbe_mode_info_structure*)0x5C00;
// int current_x = 0; //(0,*VIDEO_X)
// int current_y = 0;
//
// void printChar(const char c){
// 	//unsigned char * char_map;
// 	//char_map = charMap(6);
// 	//for (int i = 0; i < 10000; i++) {
// 	//	color_t color = {121,233,112}; //RGB
// 	//	putPixel(vbe->framebuffer, i,i,color);
// 	//}
// 	// for (int i = 0; i < CHAR_WIDTH; i++) {
// 	// 	for (int j = 0; j < CHAR_HEIGHT; j++) {
// 	// 		putPixel(vbe->framebuffer, current_x++, current_y++, COLOUR);
// 	// 	}
// 	// }
//
// 	unsigned char * charmapeado = charMap(c);
// 	for (int i=0; i<CHAR_WIDTH; i++){
// 		for (int j=0; j<CHAR_HEIGHT; j++){
// 			color_t color = {111, 158, 230};
// 			putPixel(vbe->framebuffer, current_x++, current_y++, color);
// 		}
// 	}
// }
//
// void putPixel(uint32_t where, int x, int y, color_t color) {
// 		unsigned char * pixel_address;
// 		pixel_address = (unsigned char * )(where + (vbe->bpp/8)*(x + y*vbe->width));
// 		for (int i = 0; i < vbe->bpp/8; i++) {
// 			*(pixel_address+i) = color+i;
// 		}
// }

// ----------------- VERSION TPE VIEJO -------------------------

//
//
// unsigned char * getVideoPix(){
// 	return *video_start;
// }
//
// void printString( const char* string, int B, int G, int R){
// 	int len = strleng(string);
// 	int i;
// 	for(i=0;i<len;i++){
// 		writeChar(string[i],B,G,R);
// 	}
// }
// void printReg(char* s){
// 	printString(s,0,155,255);
// }
//
// int boundedPixel(int x, int y) {
// 	return (x >= 0) && (x <= SCREEN_WIDTH) && (y >= 0) && (y <= SCREEN_HEIGHT);
// }
//
// void paintBackGround(){
// 	for(int i=0; i<SCREEN_WIDTH; i+=8){
// 		for(int j=0; j<SCREEN_HEIGHT; j+=16){
// 			paintCharSpace(i,j,BG_B,BG_G,BG_R);
// 		}
// 	}
// }
//
// void paintCharSpace(int current_x, int current_y, char B, char G, char R){
// 	for(int i=0; i<8; i++){
// 		for(int j=0; j<16; j++){
// 			paintPixel(current_x+i, current_y+j, B, G, R);
// 		}
// 	}
// }
//
// void paintPixel(int x, int y, char B, char G, char R) {
// 	if (!boundedPixel(x, y))
// 		return;
//
// 	unsigned char * pixel_address;
// 	pixel_address = getVideoPix() + 3*(x + y*SCREEN_WIDTH);
// 	*pixel_address = B;
// 	*(pixel_address+1) = G;
// 	*(pixel_address+2) = R;
// }
//
// void writeChar(char c, int B, int G, int R){
// 	checkLine();
// 	if (c < 31){
// 		if (c =='\n'){
// 			newLine();
// 			return;
// 		}
// 		if (c== 8){	//BACKSPACE
// 			backSpace();
// 			return;
// 		}
// 	}
// 	else{
// 		unsigned char * bitmap = pixel_map(c);
// 		unsigned char bitmap_aux;
// 		int x_counter;
// 		int y_counter;
//
// 		for(y_counter = 0;y_counter<16;y_counter++){
// 			for(x_counter = 0;x_counter<8;x_counter++){
//
// 				bitmap_aux = bitmap[y_counter];
// 				bitmap_aux >>= 8-x_counter;
//
// 				if(bitmap_aux%2 == 1)
// 					paintPixel(current_x+x_counter,current_y+y_counter,B,G,R);
// 				else{
// 					paintPixel(current_x+x_counter,current_y+y_counter,BG_B,BG_G,BG_R);
// 				}
// 			}
// 		}
// 		current_x += 8;
// 	}
// }
// void backSpace(){
// 	if(current_x > 3*8){
// 		current_x-=8;
// 		paintCharSpace(current_x, current_y, BG_B, BG_G, BG_R);
// 	}
// }
// void checkLine(){
// 	if(current_x>=SCREEN_WIDTH){
// 		current_x=0;
// 		current_y+=16;
// 		if(current_y>=SCREEN_HEIGHT){
// 			current_y-=16;
// 			shiftVideo();
// 		}
// 	}
// }
//
// int countDigits(int num){
// 	int dig = 1;
// 	while((num/=10) != 0) dig++;
// 	return dig;
// }
//
// void printInt(int num, int B, int G, int R){
// 		int dig = countDigits(num);
// 		char numbers[MAX_DIGITS] = {};
// 		int count=0;
//
// 		while(count!=dig){
// 			numbers[dig-1-count++]=num%10+48;
// 			num /= 10;
// 		}
//
// 		numbers[dig]='\0';
//
// 		if (num<0)
// 			writeChar('-',B,G,R);
//
// 		printString(numbers,B,G,R);
// }
// void printHex(uint64_t num){
// 	static char buffer[64] = { '0' };
// 	uintToBase(num,buffer,16);
// 	printString(buffer,0,155,255);
// }
// uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base)
// {
// 	char *p = buffer;
// 	char *p1, *p2;
// 	uint32_t digits = 0;
//
// 	//Calculate characters for each digit
// 	do
// 	{
// 		uint32_t remainder = value % base;
// 		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
// 		digits++;
// 	}
// 	while (value /= base);
//
// 	// Terminate string in buffer.
// 	*p = 0;
//
// 	//Reverse string in buffer.
// 	p1 = buffer;
// 	p2 = p - 1;
// 	while (p1 < p2)
// 	{
// 		char tmp = *p1;
// 		*p1 = *p2;
// 		*p2 = tmp;
// 		p1++;
// 		p2--;
// 	}
//
// 	return digits;
// }
// void clearScreen(){
// 	for(int i=0; i<SCREEN_WIDTH; i+=8){
// 		for(int j=0; j<SCREEN_HEIGHT; j+=16){
// 			paintCharSpace(i,j,BG_B,BG_G,BG_R);
// 		}
// 	}
// 	current_x=0;
// 	current_y=SCREEN_HEIGHT-16;
// }
//
// int strleng(const char *str){
// 	int i=0;
// 	while(*(str+i)) i++;
// 	return i;
// }
//
// void newLine(){
// 	current_x=0;
// 	current_y+=16;
// 	if(current_y>=SCREEN_HEIGHT){
// 		current_y-=16;
// 		shiftVideo();
// 	}
// }
// void shiftVideo(){
// 	//memcpy(getVideoPix, getVideoPix+3*SCREEN_WIDTH, 3*(SCREEN_HEIGHT-16)*(SCREEN_WIDTH));
// 	unsigned char B;
// 	unsigned char G;
// 	unsigned char R;
// 	unsigned char * pixel_address;
// 	for(int i=0; i<SCREEN_WIDTH;i++){
// 		for(int j=16; j<SCREEN_HEIGHT;j++){
// 			pixel_address = getVideoPix() + 3*(i + j*SCREEN_WIDTH);
// 			B=*(pixel_address);
// 			G=*(pixel_address+1);
// 			R=*(pixel_address+2);
// 			paintPixel(i,j-16,B,G,R);
// 		}
// 	}
// 	int j=SCREEN_HEIGHT-16;
// 	for(int i=0; i<SCREEN_WIDTH;i+=8){
// 		paintCharSpace(i,j,BG_B,BG_G,BG_R);
// 	}
// }
