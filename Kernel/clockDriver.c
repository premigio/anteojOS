#include <videoDriver.h>
#include <clockDriver.h>

void showClock()
{
  short show = 1;
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
  short h, m, s;
  char c;
  while (show) {
    h = getHour();
    m = getMin();
    s = getSec();
    drawClock(h,m,s,colour);
    c = '1';
    //c = getChar();
    if (c == 'q') {
        show = 0;
    } else if(c>= '0' && c<='9'){
      colour = colours[c - '0'];
    }
  }
}
