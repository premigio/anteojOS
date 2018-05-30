#ifndef CLOCK_H_
#define CLOCK_H_

#define CLOCKSIZE 8
#define CLOCKSCALE 2

typedef struct Colour					// un color es la combinacion de los colores primarios
{
 	int red;
 	int green;
 	int blue;
} Colour;

void showClock();

#endif
