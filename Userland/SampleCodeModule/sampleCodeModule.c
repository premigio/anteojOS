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
    Colour image1[128*128*8];
    Colour b;
    for (int i = 0; i <128 ; ++i) {
        for (int j = 0; j < 128; ++j) {
            unsigned short hexValue = biohazard2_XL[i*128 + j];
            b.red = ((hexValue >> 16) & 0xFF) ;  // Extract the RR byte
            b.green = ((hexValue >> 8) & 0xFF);   // Extract the GG byte
            b.blue = ((hexValue) & 0xFF);
            userDrawPixel(500+j,500+i,b.red, b.green, b.blue);
            image1[i*128+ j] = b;
/*            if (biohazard2_XL[i*128 + j] != 0){

                userDrawPixel(j,i,b.red, b.green, b.blue);
            } else{
                userDrawPixel(j,i,a.red, a.green, a.blue);
            }*/
        }
    }

    //renderBitmap(image1, c, a, biohazard2_XL, 128, 128, 8);
    //drawImage(0, 0,image1,128,128);
    drawImage2(300, 300,image1,128,128);
  return 0;
}
