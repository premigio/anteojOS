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
void timeElapsed()
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
void setFontColour(uint8_t r, uint8_t g, uint8_t b)
{
    syscall(11,r,g,b, 0,0);
}
int newToRead(unsigned int rdi, unsigned int rsi, const unsigned short *rdx, unsigned int rcx, unsigned int r8)
{
    return syscall(12,0,0,0,0,0);
}
int notifyExitRequest(unsigned int rdi, unsigned int rsi, const unsigned short *rdx, unsigned int rcx, unsigned int r8)
{
    return syscall(13,0,0,0,0,0);
}
int putChar(char c)
{
    return syscall(14,c,0,0,0,0);
}
int removeChar()
{
    return syscall(15,0,0,0,0,0);
}
void setBackgroundColour(uint8_t r, uint8_t g, uint8_t b)
{
    syscall(16,r,g,b, 0,0);
}
void setCoordinates(unsigned int x, unsigned int y)
{
    syscall(17, (uint64_t)x, (uint64_t)y, 0, 0, 0);
}
