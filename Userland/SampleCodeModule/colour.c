#include "colour.h"

static Colour fontColour = {242, 213, 96};
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

int equalColour(Colour c1, Colour c2)
{
  if (c1.red == c2.red && c1.blue == c2.blue && c1.green == c2.green)
    return 1;
  return 0;
}
