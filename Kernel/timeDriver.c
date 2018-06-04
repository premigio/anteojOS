#include <timeDriver.h>

static unsigned long ticks = 0;

void timerHandler()
{
    ticks++;
}

int ticksToSeconds(unsigned int ticks)
{
    return ticksElapsed() / TICKSPERSEC; // 18 ticks por segundo => 0.018 ticks por milisegundo
}

int ticksElapsed()
{
    return ticks;
}

int secondsElapsed()
{
    return ticksToSeconds(ticks);
}
