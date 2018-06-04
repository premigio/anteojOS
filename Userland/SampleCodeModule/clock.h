#ifndef CLOCK_H_
#define CLOCK_H_

#include "videoModule.h"
#include "colours.h"
#include <stdint.h>
#include "piloNumbers.h"
#include "scLib.h"
#include "timezone.h"

#define CLOCKSIZE 8

void drawClock(int h, int m, int s,Colour, Colour bColour );
void showClock();

#endif
