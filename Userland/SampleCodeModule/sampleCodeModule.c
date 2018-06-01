/* sampleCodeModule.c */
#include "clock.h"
#include <stdint.h>
#include "videoModule.h"
#include "SevenSegNumFontPlus.h"

int main()
{
    Colour c = {123,255,121};
    Colour a = {35, 100, 255};
    Colour image[100] = {
            a,a,a,a,c,c,a,a,a,a,
            a,a,a,a,c,c,a,a,a,a,
            a,a,a,a,c,c,a,a,a,a,
            a,a,a,a,c,c,a,a,a,a,
            a,a,a,a,c,c,a,a,a,a,
            c,c,c,c,c,c,c,c,c,c,
            a,a,a,a,c,c,a,a,a,a,
            a,a,a,a,c,c,a,a,a,a,
            a,a,a,a,c,c,a,a,a,a,
            a,a,a,a,c,c,a,a,a,a
    };
    drawImage(0, 0, image, 10, 10);
/*  Colour image[100][100];
  Colour colour = {123,255,121};

  for (int i = 0; i < 100; ++i) {
      for (int j = 0; j < 100; ++j) {
          drawPixelWithColour(100+i,100+j,colour);
          //image[i][j] = colour;
      }
  }

  drawImage(100, 100,image, 100, 100);*/
    Colour fColour = {123,255,121};
    Colour bColour = {255,255,255};

    Colour image1[32*50];

    renderBitmap(image1, fColour, bColour, (const unsigned char *) (const char *) charMap(1), 32, 50, 4);
    //drawImage(100, 100, image1, 32, 50);

    //showClock();
    //Colour colour = {123,255,121};
    //drawCharWithColour(0,colour);
  return 0;
}
