#include "timezone.h"

static int currentTimezone = DEFAULT_TIME_ZONE;

void changeTimeZone(int timezone)
{
    currentTimezone = timezone;
}
int getTimeZone()
{
    return currentTimezone;
}
int getTimezoneHour(){
    return (getHour()+currentTimezone)%TIME_FORMAT;
}