/* sampleCodeModule.c */
#include <stdint.h>
#include "scLib.h"
#include "shell.h"


int main()
{
    //parseAndInterpret("echo hola\n");
    shell();
    //Colour c = {255,255,255};
    //changeFontColour(c);
    //int c = strlen("hola");
    //putChar(c + '0');
    //putChar(c);
    //printF("%s ", "scooby doo papa Y el BOOM BOOM BOOM BOOM BOOM");
    //write("Fin2");
/*
    for (int i = 0; i < COLOURS_AMOUNT; ++i) {
        changeFontColour(userColours[i]);
        write("jadslkfñasdkfl");
    }
    char c;
    int ask = 1;
    while (ask){
        if (newToRead()){
            //printF("holamundo2");
            c = getChar();
            if (c == 'q'){// nos vamos
                ask = 0;
            }else if (isDigit(c)){
                changeFontColour(userColours[c-'0']);
                ask = 0;
            }
        }
    }
    */

    return 0;
}
