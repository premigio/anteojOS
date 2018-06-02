#include <stdint.h>
#include "colours.h"
#include "syscall.h"

void write(char * string)
{
    syscall(1,(uint64_t) string, 0,0,0,0);
}
char read()
{
    return syscall(2,0,0,0,0,0);
}

unsigned int getHour()
{
    return syscall(3,0,0,0,0,0);
}

unsigned int getMinute()
{
    return syscall(4,0,0,0,0,0);
}

unsigned int getSecond()
{
    return syscall(5,0,0,0,0,0);
}
void beep()
{
    syscall(6,0,0,0,0,0);
}
void timeElapsed()
{
    syscall(7,0,0,0,0,0);
}
void sleep(unsigned int rdi)
{
    syscall(8,(uint64_t)rdi,0,0,0,0);
}
void userDrawPixel(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    syscall(9,(uint64_t)rdi,(uint64_t)rsi,(uint64_t)rdx,(uint64_t)rcx,(uint64_t)r8);
}
void getResolutions(unsigned int * rdi, unsigned int * rsi)
{
    syscall(10,(uint64_t)rdi,(uint64_t)rsi,0,0,0);
}
void setFontColour(uint8_t R, uint8_t G, uint8_t B)
{
    syscall(11,(uint64_t)R, (uint64_t)G, (uint64_t)B,0,0);
}
void printImage(unsigned int rdi, unsigned int rsi, const unsigned short *rdx, unsigned int rcx, unsigned int r8)
{
    syscall(12,(uint64_t)rdi,(uint64_t)rsi,(uint64_t)rdx,(uint64_t)rcx,(uint64_t)r8);
}
int newToRead(unsigned int rdi, unsigned int rsi, const unsigned short *rdx, unsigned int rcx, unsigned int r8)
{
    return syscall(13,0,0,0,0,0);
}
int notifyExitRequest(unsigned int rdi, unsigned int rsi, const unsigned short *rdx, unsigned int rcx, unsigned int r8)
{
    return syscall(14,0,0,0,0,0);
}
void newWindow(unsigned int rdi, unsigned int rsi, const unsigned short *rdx, unsigned int rcx, unsigned int r8)
{
    syscall(15,0,0,0,0,0);
}
int putChar(char c){
    return syscall(16,c,0,0,0,0);
}
int removeChar(){
    return syscall(17,0,0,0,0,0);
}

