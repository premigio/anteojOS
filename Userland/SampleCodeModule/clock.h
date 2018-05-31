#ifndef CLOCK_H_
#define CLOCK_H_

const CLOCKSIZE = 8;
const CLOCKFONTHIEGHT = 10;
const CLOCKFONTWIDTH  = 5;

typedef struct Colour					// un color es la combinacion de los colores primarios
{
 	int red;
 	int green;
 	int blue;
} Colour;

void showClock();

#endif
