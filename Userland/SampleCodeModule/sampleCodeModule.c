/* sampleCodeModule.c */
#include "include/clock.h"
#include <stdint.h>
#include "include/videoModule.h"
#include "include/piloNumbers.h"
#include "include/biohazard2_XL.h"
#include "include/scLib.h"

int main()
{
    write("hola");

    /*
    //showClock();
    //Colour colour = {123,255,121};
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
    drawImage2(600, 600, image, 10, 10);
    /*Colour image1[128*128];
    Colour image2[128*128];*/
/*

    renderBitmap((Colour **) image2, biohazard2_XL, 128, 128);
    drawImage2(0, 0, image2, 128, 128);

    Colour b;
    for (int i = 0; i <128 ; ++i) {
        for (int j = 0; j < 128; ++j) {
            write("hoa");
            unsigned short hexValue = biohazard2_XL[i*128 + j];
            b.red = (uint8_t) ((hexValue >> 16) & 0xFF);  // Extract the RR byte
            b.green = (uint8_t) ((hexValue >> 8) & 0xFF);   // Extract the GG byte
            b.blue = (uint8_t) ((hexValue) & 0xFF);
            //drawAPixelWithColour(500+j,500+i,b);

            //image1[i*128+ j] = b;
        }
    }


    //drawImage2(300, 300,image1,128,128);
            */
  return 0;
}
