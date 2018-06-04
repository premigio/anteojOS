#include "clock.h"

void showClock()
{
    short show = 1;
    short h, m, s, oh, om, os = -1;
    char c = '4';
    Colour bColour = getCurrentBackgroundColour();
    Colour fColour = getCurrentFontColour();
    newWindow();
    while (show)
    {
        h = getHour();
        m = getMinute();
        s = getSecond();
        h = getTimezoneHour();
        if (oh!=h || om!=m || os!=s)
        {
            drawClock(h,m,s,fColour, bColour);

            oh = h;
            om = m;
            os = s;
        }
        c = getChar();
        if (c == 'q')
        {
            show = 0;
        }
        else if(c>= '0' && c<='9')
        {
            fColour = userColours[c -'0'];
            drawClock(h,m,s,fColour, bColour);
            kernelBeep();
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
    //write("adfjksad");

}