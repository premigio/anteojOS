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
    Colour a = {123,255,121};
    Colour c = {255,255,255};
    pColour = a;
    bColour = c;
    Colour image1[32*50];
    start = image1;
    bitMap = charMap(0);
    width = 32;
    height= 50;
    charsPerRow = 4;
    int bitsPerChar = 8;

    int j,i,k;
    for (j = 0; j < height; j++) { // cda fila
        for (k = 0; k < charsPerRow; k++) { // cada char
            for (i = 0; i < bitsPerChar; i++) { // cada bit
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
    drawImage(100, 200, start, 32, 50);
}

void drawAPixelWithColour(int x, int y, Colour col)
{
    syscall(9, x, y, col.red, col.green, col.blue);
}

