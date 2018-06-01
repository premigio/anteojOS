/* sampleCodeModule.c */
#include "clock.h"
#include <stdint.h>
#include "videoModule.h"
#include "piloNumbers.h"

int main()
{

/*  Colour image[100][100];
  Colour colour = {123,255,121};

  for (int i = 0; i < 100; ++i) {
      for (int j = 0; j < 100; ++j) {
          drawPixelWithColour(100+i,100+j,colour);
          //image[i][j] = colour;
      }
  }
    */
    showClock();
    //Colour colour = {123,255,121};
    //drawCharWithColour(0,colour);
    Colour c = {123,255,121};
    Colour a = {35, 100, 255};
    Colour image[100] = {
            a,a,a,a,c,c,a,a,a,a,
            a,c,c,a,c,c,a,c,c,a,
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
  return 0;
}
