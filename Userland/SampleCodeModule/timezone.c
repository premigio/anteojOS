#include "timezone.h"

int currentTimezone = DEFAULT_TIME_ZONE;

void changeTimeZone(int timezone)
{
    currentTimezone = timezone;
}
int getTimeZone()
{
    return currentTimezone;
}
int getTimezoneHour()
{
    return mod(getHour()+getTimeZone(), TIME_FORMAT);
}
int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}
