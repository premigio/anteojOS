#ifndef COLOURS_H_
#define COLOURS_H_

#include <stdint.h>

#define COLOURS_AMOUNT 9
#define WHITE 0
#define BLACK 1

typedef struct Colour					// un color es la combinacion de los colores primarios
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
        {11,133,3},
};

#endif