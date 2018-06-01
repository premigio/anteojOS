#include <timeDriver.h>
#include <videoDriver.h>

static const short TICKSPERSEC = 18;
static const short TICKSPERMILSEC = 0.018;
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

void kernelSleep(unsigned int miliSec){
    /*unsigned long old = ticks; // es tan largo que las chances de overflow son nulas
    while ((ticks - old) / TICKSPERMILSEC){

    }*/
    for (int i = 0; i < 100000000; i++) {

    }
}