#include "colour.h"

static Colour fontColour = {255,255,255};
static Colour backColour = {1,1,1};

void changeFontColour(Colour col)
{
    fontColour = col;
    setFontColour(fontColour.red, fontColour.green, fontColour.blue);
}
void changeBackgroundColour(Colour col)
{
    backColour = col;
    setBackgroundColour(backColour.red,backColour.green, backColour.blue );
}
Colour getCurrentFontColour()
{
    return fontColour;
}
Colour getCurrentBackgroundColour()
{
    return backColour;
}