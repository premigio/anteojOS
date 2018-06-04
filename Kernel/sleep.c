#include "include/sleep.h"

void kernelSleep(unsigned long sleep){
    unsigned long old = ticksElapsed();
    while ((ticksElapsed() - old) < sleep){}
}
