#include "video.h"

unsigned int currentX = 0;
unsigned int currentY = 0;

unsigned int xRes = 0;
unsigned int yRes = 0;


void setClockCoordinates(unsigned int *x, unsigned int *y)
{
    check();
    currentX = xRes/2 - (NUMWIDTH*CLOCKSIZE/2);
    currentY = yRes/2 - (NUMHEIGHT/2);
    *x = currentX;
    *y = currentY;
}

void check()
{
    if (xRes == 0 || yRes == 0)
    {
        getResolutions(&xRes,&yRes);
    }
}

void drawImage(unsigned int ox, unsigned int oy, const unsigned short* hexaMap, unsigned int width, unsigned int height)
{
    printImage(ox,oy,hexaMap,width,height);
}

void drawPixelImage(unsigned int ox, unsigned int oy, Colour *pixelMap, unsigned int width, unsigned int height)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            drawAPixelWithColour(ox + j, oy + i, pixelMap[i * width + j]);
        }
    }
}

void drawAPixelWithColour(int x, int y, Colour col)
{
    userDrawPixel(x,y,col.red,col.green,col.blue);
}

void drawFont(int x, int y,const char* (*getFont)(int,int), int font,Colour fColour,Colour bColour)
{
    for (int i = 0; i < NUMHEIGHT; i++)
    {
        const char * bitString = (*getFont)(font,i);

        for (int j = 0; j < NUMWIDTH; j++)
        {
            if (bitString[j] == '1')
            {
                drawAPixelWithColour(x+j,y+i,fColour);
            }
            else
            {
                drawAPixelWithColour(x+j,y+i,bColour);
            }
        }
    }
}

void drawImageFromHexaMap(unsigned  int ox, unsigned int oy, const unsigned short* hexaMap, unsigned int width, unsigned int height)
{
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

void renderFont(Colour * start,const char* (*getFont)(int,int), int font,Colour fColour,Colour bColour)
{
    for (int i = 0; i < NUMHEIGHT; i++)
    {
        const char * bitString = (*getFont)(font,i);

        for (int j = 0; j < NUMWIDTH; j++)
        {
            if (bitString[j] == '1')
            {
                start[i*NUMWIDTH +j] = fColour;
            }
            else
            {
                start[i*NUMWIDTH +j] = bColour;
            }
        }
    }
}


void renderBitmap(Colour ** start, const unsigned short* bitMap, unsigned int width, unsigned int height)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            unsigned short hexValue = bitMap[i*width + j];
            (*start)[i*width + j].red =   (hexValue >> 16) & 0xFF;
            (*start)[i*width + j].green = (hexValue >> 8) & 0xFF;
            (*start)[i*width + j].blue =  (hexValue) & 0xFF;
        }
    }
}