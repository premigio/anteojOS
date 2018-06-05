#ifndef CLOCK_H_
#define CLOCK_H_

#include "colour.h"
#include "video.h"
#include <stdint.h>
#include "piloNumbers.h"
#include "scLib.h"
#include "timezone.h"
#include "stdio.h"

#define CLOCKSIZE 8
#define SCREEN_SAVER_MODE 1
#define SCREEN_SAVER_CHANGE1 6
#define SCREEN_SAVER_CHANGE2 SCREEN_SAVER_CHANGE1+ 4
#define NORMAL_MODE 0

/* draws a clock with a given time, a colour for the digits, and a colour for the background */
void drawClock(int , int , int ,Colour, Colour);

/* draws a clock with a given time zone */
void showClock(int);

#endif
