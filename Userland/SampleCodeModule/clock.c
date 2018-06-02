#include "clock.h"
#include "videoModule.h"
#include "colours.h"
#include <stdint.h>
#include "piloNumbers.h"
#include "scLib.h"

#define TIME_FORMAT 24

void showClock(int timeZone)
{
    short show = 1;
    short h, m, s, oh, om, os = -1;
    char c = '4';
    Colour bColour = userColours[0];
    Colour fColour = userColours[1];
    newWindow();
    while (show)
    {
        h = getHour();
        m = getMinute();
        s = getSecond();
        h = (h+timeZone)%TIME_FORMAT;
        if (oh!=h || om!=m || os!=s)
        {
            drawClock(h,m,s,fColour, bColour);

            oh = h;
            om = m;
            os = s;
        }
        c = read();
        if (c == 'q')
        {
            show = 0;
        }
        else if(c>= '1' && c<='5')
        {
            fColour = userColours[c - '0'];
            drawClock(h,m,s,fColour,  bColour);
            beep();
        }
        else if((c>= '6' && c<='9' )|| c == '0')
        {
            bColour = userColours[c - '0'];
            drawClock(h,m,s,fColour,  bColour);
            beep();
        }
    }
}


void drawClock(int h, int m, int s,Colour fColour, Colour bColour)
{
    unsigned int  x, y;
    setClockCoordinates(&x,&y);
    Colour font[NUMWIDTH*NUMHEIGHT];
    renderFont(font,getNumber,h/10,fColour,bColour);
    drawPixelImage(x, y, font, NUMWIDTH, NUMHEIGHT);
    x = x + NUMWIDTH;
    renderFont(font,getNumber,h%10,fColour,bColour);
    drawPixelImage(x, y, font, NUMWIDTH, NUMHEIGHT);
    x = x + NUMWIDTH;
    renderFont(font,getNumber,COLON,fColour,bColour);
    drawPixelImage(x, y, font, NUMWIDTH, NUMHEIGHT);
    x = x + NUMWIDTH;
    renderFont(font,getNumber,m/10,fColour,bColour);
    drawPixelImage(x, y, font, NUMWIDTH, NUMHEIGHT);
    x = x + NUMWIDTH;
    renderFont(font,getNumber,m%10,fColour,bColour);
    drawPixelImage(x, y, font, NUMWIDTH, NUMHEIGHT);
    x = x + NUMWIDTH;
    renderFont(font,getNumber,COLON,fColour,bColour);
    drawPixelImage(x, y, font, NUMWIDTH, NUMHEIGHT);
    x = x + NUMWIDTH;
    renderFont(font,getNumber,s/10,fColour,bColour);
    drawPixelImage(x, y, font, NUMWIDTH, NUMHEIGHT);
    x = x + NUMWIDTH;
    renderFont(font,getNumber,s%10,fColour,bColour);
    drawPixelImage(x, y, font, NUMWIDTH, NUMHEIGHT);
    x = x + NUMWIDTH;

}