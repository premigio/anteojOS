#include "videoModule.h"
#include "clock.h"
#include <stdint.h>

unsigned int currentX = 0;
unsigned int currentY = 0;

unsigned int xRes = 0;
unsigned int yRes = 0;

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
    check();
    int counter = 0;
    for (int i = 0; i < width-1; ++i) {
        for (int j = 0; j < height-1; ++j) {
            drawPixel(ox+i , oy+j, pixelMap+counter++);
        }
    }
}

void drawPixel(unsigned int x, unsigned int y, Colour* pixel){
    syscall(9, x, y, pixel->red, pixel->green, pixel->blue);
}