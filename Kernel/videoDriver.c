#include <videoDriver.h>
#include <font.h>
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

modeInfoVBE vbe = (modeInfoVBE)0x0000000000005C00;
unsigned int currentX = 0;
unsigned int currentY = 0;
Colour background = {0, 0, 0};									// color NEGRO --> lo usamos para borrar caracteres
Colour font = {255, 255, 255};                  // color BLANCO

void drawAPixelWithColour(unsigned int x, unsigned int y, Colour col)
{
    uint8_t * video = (uint8_t*) (vbe->physBasePtr + vbe->pitch * currentY + vbe->bitsPerPixel/8 * currentX);
    video[0] = col.blue;				// un pixel ocupa 3 bytes, en cada uno le asignamos un color primario para pintarlo
    video[1] = col.green;
    video[2] = col.red;
}

void drawAPixel(unsigned int x, unsigned int y)
{
    char * video = (char *) (uint64_t)(vbe->physBasePtr + vbe->pitch * currentY + currentX * (int)(vbe->bitsPerPixel/8));
    video[0] = font.blue;				// un pixel ocupa 3 bytes, en cada uno le asignamos un color primario para pintarlo
    video[1] = font.green;
    video[2] = font.red;
}

int coordanteOutOfBounds(unsigned int x, unsigned int y)
{
		return x>=0 && x<=vbe->xResolution && y>=0 && y<=vbe->yResolution;
}

void drawChar (const char c)
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
				char * character = charMap((int)c);
				for (int j=0; j<charHeight; j++)			// primero itero en j por como esta hecho el font
				{
					for (int i=0; i<charWidth; i++)
					{
            if (1<<i & character[j])         // character[j] = 'X'
            {
              drawAPixelWithColour(charWidth - 1 - i + currentX, j + currentY, font);
            }
            else
            {
              drawAPixelWithColour(charWidth - 1 - i + currentX, j + currentY, background);
            }
					}
				}
				currentX += charWidth;
		}
}

void drawString(char * string)
{
	int n = length(string);
	for (int i=0; i<n; i++)
	{
		drawChar(string[i]);
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
			drawAPixelWithColour(x+i, y+j, background);			// no puedo usar drawChar porque esta seteado para que dibuje a partir de x e y --> pinto píxeles
		}
	}
}

void scroll ()
{
	Colour col;
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
			drawAPixelWithColour(i, j, background);
		}
	}
}

void paintWindow(Colour col)
{
  background=col;
	for (int j=0; j<vbe->yResolution; j++)
	{
		for (int i=0; i<vbe->xResolution; i++)
		{
			drawAPixelWithColour(i, j, col);
		}
	}
}
