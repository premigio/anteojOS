#ifndef _VIDEOMODULE_h
#define _VIDEOMODULE_h

#include "colours.h"

void setClockCoordinates();

void check();

void drawImage(unsigned int ox, unsigned int oy, Colour *pixelMap, unsigned int width, unsigned int height);
//bitmap is es ya el caracter,
void renderBitmap(Colour * start, Colour fColour, Colour bColour, const unsigned char* bitMap, int height, int width, int charsPerRow);

void drawAPixelWithColour(int x, int y, Colour col);

#endif