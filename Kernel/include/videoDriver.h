#ifndef VIDEODRIVER_H_
#define VIDEODRIVER_H_

#include <stdint.h>
#include <font.h>

#define charWidth 8
#define charHeight 16
#define SPACE_BETWEEN_LINES 4

typedef struct Colour
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

/* draws a pixel with the default font colour */
void drawAPixel(unsigned int, unsigned int);

/* draws a pixel with a given font colour */
void drawAPixelWithColour(int, int, Colour);

/* draws a character with the default font colour */
void drawChar(char);

/* draws a character with a given colour */
void drawCharWithColour(char, Colour);

/* draws a string with the default font colour */
void drawString(const char *);

/* draws a string with specified font colour */
void drawStringWithColour(const char *, Colour);

/* sets the font colour */
void setFontColour(Colour);

/* paints the current window with a given colour */
void paintWindow(Colour);

/* paints the current window with the default background colour */
void newWindow ();

/* makes an enter or a new line */
void enter();

/* sets the background colour */
void setBackgroundColour(Colour);

/* returns the width resolution */
int getXResolution();

/* returns the height resolution */
int getYResolution();

/* draws a given hexa value */
void drawHexa(uint64_t);

/* converts the given buffer into hexa values */
void toHexa(char *, uint64_t );

/* draws an image from given coordinates and a given hexadecimal map, with a determined width and height of image */
void drawImage(unsigned int, unsigned int, const unsigned short *hexaMap, unsigned int width, unsigned int height);

/* resets the current coordinates */
void resetCoordinates();

/* makes a backSpace on screen */
void backSpace();

/* sets current coordinates to the given ones */
void setCoord(unsigned int, unsigned int);

#endif
