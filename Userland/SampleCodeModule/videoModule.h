#ifndef _VIDEOMODULE_h
#define _VIDEOMODULE_h

#include "colours.h"
#include "clock.h"
#include <stdint.h>
#include "piloNumbers.h"
#include "scLib.h"

void setClockCoordinates(unsigned int *x, unsigned int *y);

void check();

void drawImage(unsigned int ox, unsigned int oy, const unsigned short* hexaMap, unsigned int width, unsigned int height);

void drawPixelImage(unsigned int ox, unsigned int oy, Colour *pixelMap, unsigned int width, unsigned int height);
//bitmap is es ya el caracter,
void renderBitmap(Colour ** start, const unsigned short* bitMap, unsigned int width, unsigned int height);

void drawAPixelWithColour(int x, int y, Colour col);

void drawFont(int, int, const char* (*getFont)(int,int), int font, Colour, Colour);

void drawImageFromHexaMap(unsigned  int ox, unsigned int oy, const unsigned short* hexaMap, unsigned int width, unsigned int height);

void renderFont(Colour * start,const char* (*getFont)(int,int), int font,Colour fColour,Colour bColour);
#endif