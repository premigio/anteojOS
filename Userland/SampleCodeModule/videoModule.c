#include "videoModule.h"
#include "clock.h"
#include <stdint.h>
#include "SevenSegNumFontPlus.h"
#include "scLib.h"

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
    printImage(ox,oy,pixelMap,width,height);
}

//bitmap is es ya el caracter,
void renderBitmap(Colour * start, Colour pColour, Colour bColour, const unsigned char* bitMap, int width, int height, int charsPerRow) {
    int j,i,k;
    for (j = 0; j < height; j++) {
        for (k = 0; k < charsPerRow; k++) {
            for (i = 0; i < 8; i++) {
                if ((1 << i) & bitMap[j*charsPerRow + k]) {
                    start[j * height + i] = pColour;
                    //drawAPixelWithColour(width - 1 - i , j , pColour);
                } else {
                    start[j * height + i] = bColour;
                    //drawAPixelWithColour(height - 1 - i, j , bColour);
                }
            }
        }
    }
}

void drawAPixelWithColour(int x, int y, Colour col)
{
    syscall(9, x, y, col.red, col.green, col.blue);
}

