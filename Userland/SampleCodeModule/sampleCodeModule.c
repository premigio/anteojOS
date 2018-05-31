/* sampleCodeModule.c */
#include "clock.h"
#include <stdint.h>

extern int syscall(uint64_t rdi, uint64_t rsi, uint64_t rcx, uint64_t rdx, uint64_t r8);

int main()
{
  char aux[65];
  aux[64] = 0;
  char mes[64] = "as                       ";
  int ch = 1000;
  //showClock();
  while (1)
  {
    syscall(1,mes,0,0,0);
    syscall(8,500,0,0,0);
  }
}
