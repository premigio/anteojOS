#include <beepDriver.h>

void motherBeep(){
    beepon();
    kernelSleep();
    beepoff();
}


