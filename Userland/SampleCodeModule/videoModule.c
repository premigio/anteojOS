#include "videoModule.h"
#include "clock.h"
#include <stdint.h>
#include "SevenSegNumFontPlus.h"

#define MAXRES = 10000;
#define MAXRES = 10000;

unsigned int currentX = 0;
unsigned int currentY = 0;

unsigned int xRes = 0;
unsigned int yRes = 0;

Colour backgroundColour = {0, 0, 0};
Colour fontColour = {255, 255, 255};

void setClockCoordinates(){
    check();
    currentX = xRes/2 - CLOCKSIZE/2;
    currentY = yRes/2 - CLOCKFONTHIEGHT/2;
}

void check(){
    if (xRes == 0 || yRes == 0){
        syscall(10,&xRes,&yRes);
    }
}

void drawImage(unsigned int ox, unsigned int oy, Colour *pixelMap, unsigned int width, unsigned int height){
    //check();
/*    int counter = 0;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            drawAPixelWithColour(ox+i , oy+j, pixelMap[counter++]);
        }
    }*/
    syscall(11,ox,oy,pixelMap,width,height);
}

//bitmap is es ya el caracter,
void renderBitmap(Colour * start, Colour pColour, Colour bColour, const char* bitMap, int width, int height) {
    int j,i;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            if ((1 << i) & bitMap[j]) {
                start[j*height + i] = pColour;
                //drawAPixelWithColour(CHAR_WIDTH - 1 - i + currentX, j + currentY, fColour);
            } else {
                start[j*height + i] = bColour;
                //drawAPixelWithColour(CHAR_WIDTH - 1 - i + currentX, j + currentY, backgroundColour);
            }
        }
    }
}

void drawAPixelWithColour(int x, int y, Colour col)
{
    syscall(9, x, y, col.red, col.green, col.blue);
}

