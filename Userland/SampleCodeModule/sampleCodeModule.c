/* sampleCodeModule.c */
#include "clock.h"
#include <stdint.h>
#include "videoModule.h"
#include "piloNumbers.h"
#include "biohazard2_XL.h"
#include "scLib.h"

int main()
{

    //showClock();
    //Colour colour = {123,255,121};
    write("hola");
    Colour c = {123,255,121};
    Colour a = {35, 100, 255};
    Colour image[100] = {
            a,a,a,a,c,c,a,a,a,a,
            a,c,c,a,c,c,a,c,c,a,
            a,a,a,a,c,c,a,a,a,a,
            a,a,a,a,c,c,a,a,a,a,
            a,a,a,a,c,c,a,a,a,a,
            c,c,c,c,c,c,c,c,c,c,
            a,a,a,a,c,c,a,a,a,a,
            a,a,a,a,c,c,a,a,a,a,
            a,a,a,a,c,c,a,a,a,a,
            a,a,a,a,c,c,a,a,a,a
    };
    drawImage(500, 500, image, 10, 10);
    drawImage2(300, 300, image, 10, 10);

    //drawImageFromHexaMap(600, 600, biohazard2_XL, 128, 128);

  return 0;
}
