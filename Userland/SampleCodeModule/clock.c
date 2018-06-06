#include "clock.h"

void showClock(int mode)
{
    short show = 1;
    short h, m, s, os = -1;
    char c = '4';
    Colour bColour = getCurrentBackgroundColour();
    Colour fColour = getCurrentFontColour();
    newWindow();
    while (show)
    {
        m = getMinute();
        s = getSecond();
        h = getTimezoneHour();
        if (os!=s && mode)
        {

            fColour.green = (fColour.green-SCREEN_SAVER_CHANGE1)%255;
            fColour.blue = (fColour.blue+SCREEN_SAVER_CHANGE2)%255;
            os = s;
        }
        drawClock(h,m,s,fColour, bColour);
        if(newToRead())
        {
            c = getChar();
            if (c == 'q' || mode) // si es screen saver, mode = 1 entonces mata
            {
                show = 0;
            }
            else if(c>= '1' && c<='9')
            {
                fColour = userColours[c -'0'];
                drawClock(h,m,s,fColour, bColour);
                kernelBeep();
            }
            else
            {
                newWindow();
                printF("Press 'q' to exit or a number to change the clock's colour");
                drawClock(h,m,s,fColour, bColour);
            }
        }
    }
}

void drawClock(int h, int m, int s, Colour fColour, Colour bColour)
{
    unsigned int  x, y;
    setClockCoordinates(&x,&y);
    Colour font[NUMWIDTH*NUMHEIGHT];
    int chars[] = {h/10,h%10,COLON,m/10,m%10,COLON,s/10,s%10};
    for (int i = 0; i < CLOCKSIZE; ++i) {
        renderFont(font,getNumber,chars[i],fColour,bColour);
        drawPixelImage(x, y, font, NUMWIDTH, NUMHEIGHT);
        x = x + NUMWIDTH;
    }
}
