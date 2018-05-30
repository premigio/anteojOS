/* sampleCodeModule.c */
#include "clock.h"
#include <stdint.h>

extern void syscaller(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8/*,  uint64_t r9*/);

int main() {
  // char aux[9];
  // unsigned int h, m, s;
  // syscall(5,&h,0,0,0);
  // syscall(6,&m,0,0,0);
  // syscall(7,&s,0,0,0);
  // aux[0] = h/10+'0';
  // aux[1] = h%10+'0';
  // aux[2] = ':';
  // aux[3] = m/10+'0';
  // aux[4] = m%10+'0';
  // aux[5] = ':';
  // aux[6] = s/10+'0';
  // aux[7] = s%10+'0';
  // aux[9] = 0;
  //
  // syscall(1,aux,0,0,0);
    // while (1){
    //   syscall(4,&ch);
    //   if (ch == "f"){
    //     //syscall(2,0);
    //   }
    //   syscall(3,ch);
    // }
    // while (1) {
    //   syscall(7,&ch);
    //   syscall(1,&ch);
    // }

    showClock();

    return 0;
}
