/* sampleCodeModule.c */
#include <stdint.h>

extern int syscall(uint64_t rdi, uint64_t rsi);

int main() {
  char aux[128] = {0};
  char ch;
    while (1){
      syscall(4,&ch);
      if (ch == "f"){
        syscall(2,0);
      }
      syscall(1,ch);
    }
    //syscall(1,(uint64_t)sentence);
}
