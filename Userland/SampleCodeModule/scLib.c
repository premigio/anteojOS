#include "syscall.h"
#include "scLib.h"


void write(char * string)
{
    syscall(1,(uint64_t) string, 0,0,0,0);
}
char getChar()
{
    return syscall(2,0,0,0,0,0);
}
int getHour()
{
    return syscall(3,0,0,0,0,0);
}
int getMinute()
{
    return syscall(4,0,0,0,0,0);
}
int getSecond()
{
    return syscall(5,0,0,0,0,0);
}
void kernelBeep()
{
    syscall(6,0,0,0,0,0);
}
void getTotalTicks()
{
    syscall(7,0,0,0,0,0);
}
void sleep()
{
    syscall(8,0,0,0,0,0);
}
void userDrawPixel(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    syscall(9,(uint64_t)rdi,(uint64_t)rsi,(uint64_t)rdx,(uint64_t)rcx,(uint64_t)r8);
}
void getResolutions(unsigned int * rdi, unsigned int * rsi)
{
    syscall(10,(uint64_t)rdi,(uint64_t)rsi,0,0,0);
}
void setFontColour(Colour colour)
{
    syscall(11,colour.red,colour.green,colour.blue, 0,0);
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
int putChar(char c)
{
    return syscall(16,c,0,0,0,0);
}
int removeChar()
{
    return syscall(17,0,0,0,0,0);
}
void setBackgroundColour(Colour colour)
{
    syscall(18,colour.red,colour.green,colour.blue, 0,0);
}

