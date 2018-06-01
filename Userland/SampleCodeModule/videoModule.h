#ifndef _VIDEOMODULE_h
#define _VIDEOMODULE_h

#include "colours.h"

void setClockCoordinates(unsigned int *x, unsigned int *y);

void check();

void drawImage(unsigned int ox, unsigned int oy, Colour *pixelMap, unsigned int width, unsigned int height);
void drawImage2(unsigned int ox, unsigned int oy, Colour *pixelMap, unsigned int width, unsigned int height);
//bitmap is es ya el caracter,
void renderBitmap(Colour * start, Colour pColour, Colour bColour, const unsigned short* bitMap, int width, int height, int length);

void drawAPixelWithColour(int x, int y, Colour col);

void drawFont(int, int, const char* (*getFont)(int,int), int font, Colour, Colour);

void renderFont(Colour * start,const char* (*getFont)(int,int), int font,Colour fColour,Colour bColour);
#endif