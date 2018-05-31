#ifndef TIMEDRIVER_H_
#define TIMEDRIVER_H_

//const double TICKSPERMILISEC = 0.0182; //18.2 por segundo

extern unsigned int getTime();
extern unsigned int getTimeHour();
extern unsigned int getTimeMin();
extern unsigned int getTimeSec();
extern unsigned int getTicks();
void sleep(unsigned int);

#endif
