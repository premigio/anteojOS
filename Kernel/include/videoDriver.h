#ifndef VIDEODRIVER_H_
#define VIDEODRIVER_H_
#include <stdint.h>

typedef struct Colour					// un color es la combinacion de los colores primarios
 {
 	uint8_t red;
 	uint8_t green;
 	uint8_t blue;
} colour;

typedef struct modeInfoBlock * modeInfoVBE;

void drawAPixelWithColour(unsigned int x, unsigned int y, colour col);
int coordanteOutOfBounds(unsigned int x, unsigned int y);
void drawChar (const char c, colour col);
void enter();
void backSpace();
void refreshCoordenates();
void clearCoordenate(unsigned int x, unsigned int y);
void scroll ();
void paintWindow(colour col);
void newWindow ();
void drawString(char * string, colour col);
int length (char * string);

#endif
