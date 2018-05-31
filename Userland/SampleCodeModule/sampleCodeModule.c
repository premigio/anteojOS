/* sampleCodeModule.c */
#include "clock.h"
#include <stdint.h>
#include "videoModule.h"

extern int zeroDivisionException();

extern int syscall(uint64_t rdi, uint64_t rsi, uint64_t rcx, uint64_t rdx, uint64_t r8);

int main()
{
  Colour image[1000];
  Colour colour = {123,255,121};
  for (int i = 0; i < 1000; ++i) {
    image[i] = colour;
    //drawPixel(i,i,&colour);
  }
  drawImage(123,123,image,50, 50);
  return 0;
}
