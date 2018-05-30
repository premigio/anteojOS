#include "clock.h"

void showClock()
{
  short show = 1;
  unsigned int h, m, s, oh, om, os = -1;
  char c, oc = '4';
  char times[CLOCKSIZE+1];
  Colour colours[10] = {
    {10,154,10},
    {50,50,50},
    {120,50,70},
    {120,150,120},
    {255,210,170},
    {45,237,1},
    {25,103,130},
    {60,130,161},
    {11,133,210},
    {30,176,130},
  };
  Colour colour = colours[1];
  while (show)
  {
    syscall(5,&h,0,0,0);
    syscall(6,&m,0,0,0);
    syscall(7,&s,0,0,0);
    if (oh!=h || om!=m || os!=s)
    {
      times[0] = h/10+'0';
      times[1] = h%10+'0';
      times[2] = ':';
      times[3] = m/10+'0';
      times[4] = m%10+'0';
      times[5] = ':';
      times[6] = s/10+'0';
      times[7] = s%10+'0';
      times[9] = 0;
      syscall(8, times, colour.red , colour.green , colour.blue);
      oh = h;
      om = m;
      os = s;
      c = (c - '0' +1)%10 +'0';         // esto se borra cuando pedro termine de hacer la cosas que tiene que hacer LPM! PEDRO
    }
    if (c == 'q')
    {
        show = 0;
    }
    else if(c>= '0' && c<='9')
    {
      colour = colours[c - '0'];
      syscall(8, times, colour.red , colour.green , colour.blue);
      syscall(9,0,0,0,0);
    }
  }
}
