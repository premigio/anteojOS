#include <beepDriver.h>
#include <ioDriver.h>

void motherBeep(){
    beepon();
    sleep(1000);
    beepoff();
}


