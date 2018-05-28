#include <videoDriver.h>
#include <clockDriver.h>
#include <beepDriver.h>

const CLOCK_SIZE = 8;

void showClock()
{
  short show = 1;
  int i = 0;
  Colour colour;
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
  short h, m, s, oh, om, os = -1;
  char c = 0;
  newWindow();
  setClockCoordinates();
  while (show) {
    h = getHour();
    m = getMin();
    s = getSec();
    if (oh!=h || om!=m || os!=s) {
      drawClock(h,m,s,colour);
      oh = h;
      om = m;
      os = s;
      c = (c +1)%10 +'0'; // esto se borra cuando pedro termine de hacer la cosas que tiene que hacer LPM! PEDRO
    }
    //c = getChar();
    if (c == 'q') {
        show = 0;
    } else if(c>= '0' && c<='9'){
      colour = colours[c - '0'];
      beep();
    }
  }
}
