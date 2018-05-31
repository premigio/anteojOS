#include "clock.h"
#include "videoModule.h"
#include "colours.h"

void showClock()
{
  short show = 1;
  int h, m, s, oh, om, os = -1;
  char c = '4';
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
    h = syscall(3,0,0,0,0);
    m = syscall(4,0,0,0,0);
    s = syscall(5,0,0,0,0);
    if (oh!=h || om!=m || os!=s)
    {

      drawClock(h,m,s,colour);
      //syscall(1, times, colour.red , colour.green , colour.blue);
      oh = h;
      om = m;
      os = s;
      //c = (c - '0' +1)%10 +'0';         // esto se borra cuando pedro termine de hacer la cosas que tiene que hacer LPM! PEDRO
    }

    c = (char)syscall(2,0,0,0,0);

    if (c == 'q')
    {
        show = 0;
    }
    else if(c>= '0' && c<='9')
    {
      colour = colours[c - '0'];
      drawClock(h,m,s,colour);
      //syscall(1, times, colour.red , colour.green , colour.blue);
      syscall(6,0,0,0,0);
    }
  }
}


void drawClock(int h, int m, int s,Colour colour)
{

  setClockCoordinates();

}