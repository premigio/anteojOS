#include <timeDriver.h>
#include <videoDriver.h>

static const short TICKSPERSEC = 18;
static const double TICKSPERMILSEC = 0.018;
static unsigned long ticks = 0;

void timerHandler() {
    ticks++;
}

int ticksToSeconds(unsigned int ticks) {
    return ticksElapsed() / TICKSPERSEC; // 18 ticks por segundo => 0.018 ticks por milisegundo
}

int ticksElapsed() {
    return ticks;
}

int secondsElapsed() {
    return ticksToSeconds(ticks);
}

void kernelSleep(unsigned int sec){
    for (int i = 0; i <10000000; ++i) {

    }
}