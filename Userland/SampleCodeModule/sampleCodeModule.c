/* sampleCodeModule.c */
#include <stdint.h>

extern int syscall(uint64_t rdi, uint64_t rsi);

int main() {
    char *sentence = "puto el que lee";
    unsigned int timee;
    syscall(2,&timee);
    //syscall(1,(uint64_t)sentence);
}
