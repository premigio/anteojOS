/* sampleCodeModule.c */
#include "clock.h"
#include <stdint.h>

extern int syscall(uint64_t rdi, uint64_t rsi, uint64_t rcx, uint64_t rdx, uint64_t r8);

int main()
{
  unsigned int aux[64];
  char mes[64] = "asdfasdfasdfasdfasdfasdfasdf";
  unsigned int ch;
  //showClock();
  while (1)
  {
    ch = syscall(7,0,0,0,0);
    for (int i = 0; i < 64; ++i) {
      aux[63-i] = ch%10;
      ch = ch/10;
    }
    syscall(1,aux,0,0,0);
    syscall(1,mes,0,0,0);
  }
}
