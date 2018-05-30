#include <videoDriver.h>
#include <clockDriver.h>
#include <beepDriver.h>

void drawClock(short h, short m, short s, Colour colour);
void showClock();

void showClock()
{
  short show = 1;
  Colour colour;
  short h, m, s, oh, om, os = -1;
  char c = '0';
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
  newWindow();
  while (show)
  {
    h = getHour();
    m = getMin();
    s = getSec();
    if (oh!=h || om!=m || os!=s)
    {
      drawClock(h,m,s,colour);
      oh = h;
      om = m;
      os = s;
      c = (c +1)%10 +'0';         // esto se borra cuando pedro termine de hacer la cosas que tiene que hacer LPM! PEDRO
    }
    //c = getChar();
    if (c == 'q')
    {
        show = 0;
    }
    else if(c>= '0' && c<='9')
    {
      colour = colours[c - '0'];
      //beep();
    }
  }
}

void drawClock(short h, short m, short s, Colour colour)
{
  setClockCoordinates();
  drawCharWithColour(h/10 + '0', colour);
  drawCharWithColour(h%10 + '0', colour);
  drawCharWithColour(':',colour );
  drawCharWithColour(m/10 + '0', colour);
  drawCharWithColour(m%10 + '0', colour);
  drawCharWithColour(':', colour);
  drawCharWithColour(s/10 + '0', colour);
  drawCharWithColour(s%10 + '0', colour);
}
