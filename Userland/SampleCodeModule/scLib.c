#include <stdint.h>

void write(char * string)
{
    syscall(1,(uint64_t) string, 0,0,0);
}

void read()
{
    syscall(2,0,0,0,0);
}

void getHour()
{
    syscall(3,0,0,0,0);
}

void getMinute()
{
    syscall(4,0,0,0,0);
}

void getSecond()
{
    syscall(5,0,0,0,0);
}

void beep()
{
    syscall(6,0,0,0,0);
}

void timeEllapsed()
{
    syscall(7,0,0,0,0);
}

void setFontColour(uint8_t R, uint8_t G, uint8_t B)
{
    syscall(11,(uint64_t)R, (uint64_t)G, (uint64_t)B,0);
}
