#ifndef TIMEDRIVER_H_
#define TIMEDRIVER_H_

#define TICKSPERSEC 18

extern unsigned int getTime();
extern unsigned int getTimeHour();
extern unsigned int getTimeMin();
extern unsigned int getTimeSec();

void timerHandler(void);
int ticksToSeconds(unsigned int ticks);
int ticksElapsed(void);
int secondsElapsed(void);

#endif
