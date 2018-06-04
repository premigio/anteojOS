#ifndef TIMEZONE_H
#define TIMEZONE_H

#include "scLib.h"

#define DEFAULT_TIME_ZONE -3
#define TIME_FORMAT 24

void changeTimeZone(int);
int getTimeZone();
int getTimezoneHour();


#endif