#ifndef COLOUR_H
#define COLOUR_H

#include <stdint.h>
#include "scLib.h"

#define COLOURS_AMOUNT 9

typedef struct
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Colour;

static const Colour userColours[COLOURS_AMOUNT] = {
        {1,1,1},
        {255,255,255},
        {120,50,70},
        {120,150,120},
        {255,3,170},
        {45,237,1},
        {25,103,130},
        {60,255,161},
        {11,133,3}
};

/* changes the font colour */
void changeFontColour(Colour col);

/* changes the background colour */
void changeBackgroundColour(Colour col);

/* returns the current colour */
Colour getCurrentFontColour();

/* returns the current background colour */
Colour getCurrentBackgroundColour();

#endif
