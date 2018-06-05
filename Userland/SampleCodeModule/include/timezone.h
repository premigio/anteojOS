#ifndef TIMEZONE_H
#define TIMEZONE_H

#include "scLib.h"

#define DEFAULT_TIME_ZONE -3

#define TIME_FORMAT 24

/* changes the current time zone to the given int */
void changeTimeZone(int);

/* returns the current time zone */
int getTimeZone();

/* returns the current hour in the setted time zone */
int getTimezoneHour();

int mod(int a, int b);

#endif
