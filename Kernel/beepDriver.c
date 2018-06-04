#include <beepDriver.h>

void motherBeep(){
    beepon();
    kernelSleep(TICKSPERSEC);
    beepoff();
}


