#include "videoModule.h"
#include "clock.h"
#include <stdint.h>
#include "piloNumbers.h"
#include "scLib.h"

unsigned int currentX = 0;
unsigned int currentY = 0;

unsigned int xRes = 0;
unsigned int yRes = 0;

Colour backgroundColour = {0, 0, 0};
Colour fontColour = {255, 255, 255};

void setClockCoordinates(unsigned int *x, unsigned int *y){
    check();
    currentX = xRes/2 - (NUMWIDTH*CLOCKSIZE/2);
    currentY = yRes/2 - (NUMHEIGHT/2);
    *x = currentX;
    *y = currentY;
}

void check(){
    if (xRes == 0 || yRes == 0){
        syscall(10,&xRes,&yRes);
    }
}

void drawImage(unsigned int ox, unsigned int oy, Colour *pixelMap, unsigned int width, unsigned int height)
{
    printImage(ox,oy,pixelMap,width,height);
}
void drawImage2(unsigned int ox, unsigned int oy, Colour *pixelMap, unsigned int width, unsigned int height) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            drawAPixelWithColour(ox + j, oy + i, pixelMap[i * width + j]);
        }
    }
}

void drawAPixelWithColour(int x, int y, Colour col)
{
    userDrawPixel(x,y,col.red,col.green,col.blue);
    //syscall(9, x, y, col.red, col.green, col.blue);
}
void drawFont(int x, int y,const char* (*getFont)(int,int), int font,Colour fColour,Colour bColour){

    for (int i = 0; i < NUMHEIGHT; i++) {
        const char * bitString = (*getFont)(font,i);

        for (int j = 0; j < NUMWIDTH; j++) {
            if (bitString[j] == '1'){

                drawAPixelWithColour(x+j,y+i,fColour);
            }else{
                drawAPixelWithColour(x+j,y+i,bColour);
            }
        }
    }
}

void renderFont(Colour * start,const char* (*getFont)(int,int), int font,Colour fColour,Colour bColour){

    for (int i = 0; i < NUMHEIGHT; i++) {
        const char * bitString = (*getFont)(font,i);

        for (int j = 0; j < NUMWIDTH; j++) {
            if (bitString[j] == '1'){
                start[i*NUMWIDTH +j] = fColour;
                //drawAPixelWithColour(j,i,fColour);
            }else{
                start[i*NUMWIDTH +j] = bColour;
                //drawAPixelWithColour(j,i,bColour);
            }
        }
    }
}
// no funciona
void renderBitmap(Colour * start, Colour pColour, Colour bColour, const unsigned short* bitMap, int width, int height, int pixelsPerWidth) {

    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            if (bitMap[i*width+j] != 0)
            {
                start[i*width+j] = pColour ;
                drawAPixelWithColour(j,i,pColour);
            }
            else
            {
                start[i*width+j] = bColour ;
                drawAPixelWithColour(j,i,bColour);
            }
        }
    }

}
