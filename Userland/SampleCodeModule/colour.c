#include "colour.h"

static Colour fontColour = {255,255,255};
static Colour backColour = {1,1,1};

void changeFontColour(Colour col)
{
    fontColour = col;
    setFontColour(fontColour);
}
void changeBackgroundColour(Colour col)
{
    backColour = col;
    setBackgroundColour(backColour);
}
Colour getCurrentFontColour()
{
    return fontColour;
}
Colour getCurrentBackgroundColour()
{
    return backColour;
}