#ifndef CLOCK_H_
#define CLOCK_H_

#include "colour.h"
#include "videoModule.h"
#include <stdint.h>
#include "piloNumbers.h"
#include "scLib.h"
#include "timezone.h"

#define CLOCKSIZE 8
#define SCREEN_SAVER_MODE 1
#define SCREEN_SAVER_CHANGE1 10
#define SCREEN_SAVER_CHANGE2 SCREEN_SAVER_CHANGE1+ 7
#define NORMAL_MODE 0

void drawClock(int h, int m, int s,Colour, Colour bColour );
void showClock(int mode);

#endif
