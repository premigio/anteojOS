#ifndef VIDEODRIVER_H_
#define VIDEODRIVER_H_
#include <stdint.h>

typedef struct Colour					// un color es la combinacion de los colores primarios
{
 	uint8_t red;
 	uint8_t green;
 	uint8_t blue;
} Colour;

struct modeInfoBlock
{
    uint16_t modeAttributes;
    uint8_t winAAttributes;
    uint8_t winBAttributes;
    uint16_t winGranularity;
    uint16_t winSize;
    uint16_t winSegmentA;
    uint16_t winSegmentB;
    uint32_t winRealFctPtr;
    uint16_t pitch; // Bytes per ScanLine.

    uint16_t xResolution;
    uint16_t yResolution;
    uint8_t xCharSize;
    uint8_t yCharSize;
    uint8_t numberOfPlanes;
    uint8_t bitsPerPixel;
    uint8_t numberOfBanks;
    uint8_t memoryModel;
    uint8_t bankSize;
    uint8_t numberOfImagePages;
    uint8_t reservedPage;

    uint8_t redMaskSize;
    uint8_t redMaskPosition;
    uint8_t greenMaskSize;
    uint8_t greenMaskPosition;
    uint8_t blueMaskSize;
    uint8_t blueMaskPosition;
    uint8_t reservedMaskSize;
    uint8_t reservedMaskPosition;
    uint8_t directColorAttributes;

    uint32_t physBasePtr;  // Your LFB (Linear Framebuffer) address.
    uint32_t offScreenMemOffset;
    uint16_t offScreenMemSize;
} __attribute__((packed));

//The _attribute_ modifiers are needed to make gcc pack the structure into
//the standard VESA layout, rather than adding pad bytes between some of the
//fields like it would normally do.
//http://www.delorie.com/djgpp/doc/ug/graphics/vesa.html

typedef struct modeInfoBlock * modeInfoVBE;

void drawAPixelWithColour(int x, int y, Colour col);
int coordanteOutOfBounds(unsigned int x, unsigned int y);
void drawChar (const char c);
void enter();
void backSpace();
void refreshCoordenates();
void clearCoordenate(unsigned int x, unsigned int y);
void scroll ();
void paintWindow(Colour col);
void newWindow ();
void drawString(char * string);
int length (char * string);

#endif
