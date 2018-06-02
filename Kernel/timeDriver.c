#include <timeDriver.h>
#include <videoDriver.h>

static const short TICKSPERSEC = 18;
static const double TICKSPERMILSEC = 0.018;
static unsigned long ticks = 0;

void timerHandler() {
    //char adentro[] = "adnetro deTIme HAndler";
    //drawString(adentro);
    //drawChar(ticks%10+'0');
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
    unsigned long old = ticksElapsed(); // es tan largo que las chances de overflow son nulas

    while (((ticksElapsed() - old) / TICKSPERSEC ) < sec) {
        drawChar(ticksElapsed() %10+'0');
        //drawChar(old%10+'0');
        //rest
    }
}