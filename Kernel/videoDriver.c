#include <videoDriver.h>
#include <font.h>

#define charWidth 8
#define charHeight 16

void drawAPixelWithColour(int x, int y, Colour col);
void drawAPixel(unsigned int x, unsigned int y);
void drawCharWithColour(const char c, Colour fColour);
void drawChar(const char c);
void drawStringWithColour(const char * string,  Colour fColour);
void drawString(const char * string);
void enter();
void backSpace();
void refreshCoordenates();
void clearCoordenate(unsigned int x, unsigned int y);
void scroll ();
void newWindow ();
void paintWindow(Colour col);
void setBackgroundColour(Colour col);
void setFontColour(Colour col);
int kernelRequestUserDraw();
int getXResolution();
int getYResolution();


modeInfoVBE vbe = (modeInfoVBE)0x5C00;
unsigned int currentX = 0;
unsigned int currentY = 0;
unsigned int enterXCoordenates[300];
unsigned int enterYCoordenates[300];
unsigned int sizeEnter = 0;
Colour backgroundColour = {0, 0, 0};
Colour fontColour = {255, 255, 255};

void drawAPixelWithColour(int x, int y, Colour col)
{
    char * video = (char *) ((uint64_t)(vbe->physBasePtr + vbe->pitch * y + x * (vbe->bitsPerPixel / 8)));
    video[0] = col.blue;
    video[1] = col.green;
    video[2] = col.red;
}

void drawAPixel(unsigned int x, unsigned int y)
{
	drawAPixelWithColour(x, y, fontColour);
}

void drawCharWithColour (const char c, Colour fColour)
{
		refreshCoordenates();
		if (c < 31)						// entonces no es un caracter del font.c
		{
			if ( c == '\n')
			{
				enter();				// me muevo a una nueva linea
			}
			if (c == '\b' )			// entonces quiere borrar el ultimo caracter
			{
				backSpace();
			}
		}
		else							// tengo un caracter del font.c
		{
        char * character = charMap((int)c);
        for (int j=0; j<charHeight; j++)
        {
            for (int i=0; i<charWidth; i++)
            {
            if (1<<i & character[j])
            {
              drawAPixelWithColour(charWidth - 1 - i + currentX, j + currentY, fColour);
            }
            else
            {
              drawAPixelWithColour(charWidth - 1 - i + currentX, j + currentY, backgroundColour);
            }
					}
				}
				currentX += charWidth;
		}
}

void drawChar(const char c)
{
    drawCharWithColour(c, fontColour);
}

void drawStringWithColour(const char * string, Colour fColour)
{
	int i=0;
  while (string[i])
  {
		drawCharWithColour(string[i], fColour);
    i++;
	}
}

void drawString(const char * string)
{
	drawStringWithColour(string, fontColour);
}

void enter()
{
  if (sizeEnter == 0)
  {
    int i=0;
    while ( i < vbe->yResolution )
    {
      enterXCoordenates[i]=0;
      enterYCoordenates[i]=0;
      i++;
    }
  }
  enterXCoordenates[sizeEnter] = currentX;
  enterYCoordenates[sizeEnter++] = currentY;

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
  if (currentX == 0 && currentY!=0)
  {
    sizeEnter--;
    currentX = enterXCoordenates[sizeEnter];
    currentY = enterYCoordenates[sizeEnter];
    enterXCoordenates[sizeEnter] = enterYCoordenates[sizeEnter] = 0;
  }
  else
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
  }
	clearCoordenate(currentX, currentY);					// "limpio" el lugar donde estan parados X e Y
}

void refreshCoordenates()
{
	if (currentX >= vbe->xResolution)
	{
    enterXCoordenates[sizeEnter] = currentX-charWidth;
    if (currentY < vbe->yResolution)
    {
      enterYCoordenates[sizeEnter++] = currentY;
    }
    else
    {
      enterYCoordenates[sizeEnter++] = currentY - charHeight;
    }
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
			drawAPixelWithColour(x+i, y+j, backgroundColour);
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
      pixelAddress = (char *) ((uint64_t)(vbe->physBasePtr + vbe->pitch * j + i * (int)(vbe->bitsPerPixel/8)));
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
	for (int j=0; j<vbe->yResolution; j++)
	{
		for (int i=0; i<vbe->xResolution; i++)
		{
			drawAPixelWithColour(i, j, backgroundColour);
		}
	}
}

void paintWindow(Colour col)
{
	for (int j=0; j<vbe->yResolution; j++)
	{
		for (int i=0; i<vbe->xResolution; i++)
		{
			drawAPixelWithColour(i, j, col);
		}
	}
}

void setBackgroundColour(Colour col)
{
  backgroundColour = col;
}

void setFontColour(Colour col)
{
  fontColour = col;
}

int kernelRequestUserDraw()
{
	newWindow();
	return 1;
}

int getXResolution()
{
    return vbe->xResolution;
}

int getYResolution()
{
    return vbe->yResolution;
}

void drawImage(unsigned int ox, unsigned int oy, Colour *pixelMap, unsigned int width, unsigned int height){
	refreshCoordenates();
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			drawAPixelWithColour(ox+j, oy+i, pixelMap[i*width + j]);
		}
	}
}
// void drawHexa(uint64_t reg)
// {
//   drawString("0x");
//   char n[16] = {0};
//   int j = 0;
//   while(reg >= 0)
//   {
//      n[15 - j] = toHexa(reg%16);
//      reg = reg/16;
//      j++;
//   }
//   for(int i = 0; i < 16; i++)
//   {
//      if(n[i])
//      {
//         drawChar(n[i]);
//      }
//   }
// }
void drawHexa(uint64_t number) {
      char n[16] ={0};
      int index = 0,i;
      do{
         n[15 - index] = toHexa(number%16);
         number = number/16;
         index++;
      }while(number);
      for(i = 0; i<16; i++){
         if(n[i])
            drawChar(n[i]);
      }
   }

static char toHexa(uint64_t n)
{
  char ret;
  switch(n)
  {
    case 10:
       ret = 'A';
    case 11:
       ret = 'B';
    case 12:
       ret = 'C';
    case 13:
       ret = 'D';
    case 14:
       ret = 'E';
    case 15:
       ret = 'F';
    default:
      ret = (char)(n+48);
  }
  return ret;
}
