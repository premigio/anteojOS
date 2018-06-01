#include "clock.h"
#include "videoModule.h"
#include "colours.h"
#include <stdint.h>
#include "piloNumbers.h"
#include "scLib.h"

void showClock()
{
  short show = 1;
  int h, m, s, oh, om, os = -1;
  char c = '4';
  Colour colour = userColours[1];
  while (show)
  {
    h = getHour();
    m = getMinute();
    s = getSecond();
    if (oh!=h || om!=m || os!=s)
    {

      drawClock(h,m,s,colour);

      oh = h;
      om = m;
      os = s;
      //c = (c - '0' +1)%10 +'0';         // esto se borra cuando pedro termine de hacer la cosas que tiene que hacer LPM! PEDRO
    }

    c = read();

    if (c == 'q')
    {
        show = 0;
    }
    else if(c>= '0' && c<='9')
    {
      colour = userColours[c - '0'];
      drawClock(h,m,s,colour);

      syscall(6,0,0,0,0); //beep
    }
  }
}


void drawClock(int h, int m, int s,Colour colour)
{
  setClockCoordinates();
}