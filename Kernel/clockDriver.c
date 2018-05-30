#include <videoDriver.h>
#include <clockDriver.h>
#include <beepDriver.h>
#include <keyboardDriver.h>


void drawClock(char * timeF, int r, int g, int b)
{
  Colour colour = {r,g,b};
  setClockCoordinates();
  drawStringWithColour(timeF, colour);
  
}
