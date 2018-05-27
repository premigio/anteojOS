#include <videoDriver.h>
#include <font.h>
#include <stdint.h>
#define charWidth 8
#define charHeight 16

modeInfoVBE vbe = (modeInfoVBE)0x5C00;
unsigned int currentX = 0;
unsigned int currentY = 0;
Colour backgroundColour = {0, 0, 0};
Colour fontColour = {255, 255, 255};

void drawAPixelWithColour(int x, int y, Colour col)
{
    char * video = (char *) ((uint64_t)(vbe->physBasePtr + vbe->pitch *y + x* (int)(vbe->bitsPerPixel/8)));
    video[0] = col.blue;
    video[1] = col.green;
    video[2] = col.red;
}

void drawAPixel(unsigned int x, unsigned int y)
{
	drawAPixelWithColour(x, y, fontColour);
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
				for (int j=0; j<charHeight; j++)	
				{
					for (int i=0; i<charWidth; i++)
					{
            if (1<<i & character[j])    
            {
              drawAPixelWithColour(charWidth - 1 - i + currentX, j + currentY, fontColour);
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

