#ifndef COLOURS_H_
#define COLOURS_H_

#include <stdint.h>
typedef struct Colour					// un color es la combinacion de los colores primarios
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Colour;

static const Colour userColours[10] = {
        {10,154,10},
        {50,50,50},
        {120,50,70},
        {120,150,120},
        {255,210,170},
        {45,237,1},
        {25,103,130},
        {60,130,161},
        {11,133,210},
        {30,176,130},
};

#endif