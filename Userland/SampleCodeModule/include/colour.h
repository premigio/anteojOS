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
        {242, 213, 96},
        {255,0,127}, //
        {255,204,155},
        {255,153,51},
        {45,237,1},
        {25,103,130},
        {60,255,161},
        {255,255,255}
};

/* changes the font colour */
void changeFontColour(Colour col);

/* changes the background colour */
void changeBackgroundColour(Colour col);

/* returns the current colour */
Colour getCurrentFontColour();

/* returns the current background colour */
Colour getCurrentBackgroundColour();

/* return wether two colours are equal */
int equalColour(Colour c1, Colour c2);

#endif
