#include <beepDriver.h>
#include <ioDriver.h>
#include <timeDriver.h>

void motherBeep(){
    beepon();
    kernelSleep(1000);
    beepoff();
}


