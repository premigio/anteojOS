#ifndef _VIDEOMODULE_h
#define _VIDEOMODULE_h

#include "colours.h"

void check(void);
void setClockCoordinates(void);
void drawPixel(unsigned int x, unsigned int y, Colour *pixel);
void drawImage(unsigned int ox, unsigned int oy, Colour *pixelMap, unsigned int width, unsigned int height);
int exitKernelDraw();
int requestKernelDraw();

#endif