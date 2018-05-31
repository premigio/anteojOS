#include "videoModule.h"
#include "clock.h"

unsigned int currentX = 0;
unsigned int currentY = 0;

unsigned int xRes = 0;
unsigned int yRes = 0;

short canDraw = 0;

setClockCoordinates(){
    check();
    currentX = xRes/2 - CLOCKSIZE/2;
    currentY = yRes/2 - CLOCKFONTHIEGHT/2;
}

void check(){
    if (xRes == 0 || yRes == 0){
        xRes = syscall(9);
        yRes = syscall(10);
    }
}

int requestKernelDraw(){
    canDraw = syscall(9);
    return canDraw;
}

int exitKernelDraw(){
    canDraw = 0;
}

void drawImage(unsigned int ox, unsigned int oy, Colour *pixelMap, unsigned int width, unsigned int height){
    if (!canDraw){
        if(!requestKernelDraw());
        return;
    }
    check();
    int counter = 0;
    for (int i = 0; i < width-1; ++i) {
        for (int j = 0; j < height-1; ++j) {
            drawPixel(ox+i , oy+j, pixelMap+counter++);
        }
    }
}

void drawPixel(unsigned int x, unsigned int y, Colour pixel){
    syscall(10, x, y, pixel);
}