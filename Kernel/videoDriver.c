#include <videoDriver.h>

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
int getXResolution();
int getYResolution();


modeInfoVBE vbe = (modeInfoVBE)0x5C00;        /*------> taken from /Bootloader/Pure64/src/sysvar.asm */
unsigned int currentX = 0;
unsigned int currentY = 0;
unsigned int enterXCoordenates[300];
unsigned int enterYCoordenates[300];
unsigned int sizeEnter = 0;
Colour backgroundColour = {0, 0, 0};
Colour fontColour = {242, 213, 96};

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

void drawCharWithColour ( char c, Colour fColour)
{
    refreshCoordenates();
    if (c < 31)						   // entonces no es un caracter dentro del font.c
    {
        if ( c == '\n')
        {
            enter();
        }
        if (c == '\b' )
        {
            backSpace();
        }
    }
    else
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

void drawChar( char c)
{
    if (c == '\n')
    {
        enter();
    }
    else
    {
        drawCharWithColour(c, fontColour);
    }
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
    clearCoordenate(currentX, currentY);
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
        for (int j=charHeight; j<vbe->yResolution; j++)
        {
            pixelAddress = (char *) ((uint64_t)(vbe->physBasePtr + vbe->pitch * j + i * (int)(vbe->bitsPerPixel/8)));
            col.blue = pixelAddress[0];
            col.green = pixelAddress[1];
            col.red = pixelAddress[2];
            drawAPixelWithColour(i, j-charHeight, col);
        }
    }
    int j = vbe->yResolution - charHeight;
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
    resetCoordinates();
}

void resetCoordinates()
{
    currentY = currentX = 0;
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

int getXResolution()
{
    return vbe->xResolution;
}

int getYResolution()
{
    return vbe->yResolution;
}

void drawImage(unsigned int ox, unsigned int oy, const unsigned short *hexaMap, unsigned int width, unsigned int height)
{
    refreshCoordenates();
    Colour b;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            unsigned short hexValue = hexaMap[i*width + j];
            b.red = (uint8_t) ((hexValue >> 16) & 0xFF);
            b.green = (uint8_t) ((hexValue >> 8) & 0xFF);
            b.blue = (uint8_t) ((hexValue) & 0xFF);
            drawAPixelWithColour(ox+j,oy+i,b);
        }
    }
}

void drawHexa(uint64_t reg)
{
	char buffer[64];
	toHexa(buffer, reg);
  drawString("0x");
	drawString(buffer);
}

void toHexa(char * buffer, uint64_t value)
{
  char *p = buffer;
  char *aux1, *aux2;

  do
  {
    unsigned int r = value % 16;
    *p++ = (r < 10) ? r + '0' : r + 'A' - 10;
  }
  while (value /= 16);

  *p = 0;
  aux1 = buffer;
  aux2 = p - 1;

  while (aux1 < aux2)
  {
    char tmp = *aux1;
    *aux1 = *aux2;
    *aux2 = tmp;
    aux1++;
    aux2--;
  }
  return;

}

void setCoord(unsigned int x, unsigned int y)
{
    currentX=x;
    currentY=y;
}
