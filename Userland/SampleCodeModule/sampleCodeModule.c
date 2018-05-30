/* sampleCodeModule.c */
#include <stdint.h>

extern int syscall(uint64_t rdi, uint64_t rsi, uint64_t rcx, uint64_t rdx, uint64_t r8);

int main() {
  char aux[128] = {0};
  char ch;
  while (1)
  {
    syscall(2,&ch,0,0,0);
    syscall(1,&ch,0,0,0);
  }
}
