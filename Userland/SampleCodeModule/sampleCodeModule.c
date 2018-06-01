/* sampleCodeModule.c */
#include "clock.h"
#include <stdint.h>
#include "videoModule.h"
#include "SevenSegNumFontPlus.h"

extern int zeroDivisionException();

extern int syscall(uint64_t rdi, uint64_t rsi, uint64_t rcx, uint64_t rdx, uint64_t r8);

int main()
{
    Colour c = {123,255,121};
    Colour a = {35, 100, 255};
/*    Colour image[100] = {
            c,a,c,a,c,a,c,a,c,a,
            a,c,a,c,a,c,a,c,a,c,
            c,a,c,a,c,a,c,a,c,a,
            a,c,a,c,a,c,a,c,a,c,
            c,a,c,a,c,a,c,a,c,a,
            a,c,a,c,a,c,a,c,a,c,
            c,a,c,a,c,a,c,a,c,a,
            a,c,a,c,a,c,a,c,a,c,
            c,a,c,a,c,a,c,a,c,a,
            a,c,a,c,a,c,a,c,a,c
    };*/
    //drawImage(0, 0, image, 10, 10);
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

    renderBitmap(image1, fColour, bColour, (const char *) charMap(0), 32, 50, 4);
    drawImage(100, 100, image1, 32, 50);

    //showClock();
    //Colour colour = {123,255,121};
    //drawCharWithColour(0,colour);
  return 0;
}
