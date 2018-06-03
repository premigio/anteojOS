/* sampleCodeModule.c */
#include "clock.h"
#include <stdint.h>
#include "videoModule.h"
#include "piloNumbers.h"
#include "biohazard2_XL.h"
#include "scLib.h"
#include "shell.h"
#include "stdlibJime.h"

int main()
{
/*    Colour j = {123,255,121};
    Colour a = {35, 100, 255};
    Colour image[100] = {
            a,a,a,a,j,j,a,a,a,a,
            a,j,j,a,j,j,a,j,j,a,
            a,a,a,a,j,j,a,a,a,a,
            a,a,a,a,j,j,a,a,a,a,
            a,a,a,a,j,j,a,a,a,a,
            j,j,j,j,j,j,j,j,j,j,
            a,a,a,a,j,j,a,a,a,a,
            a,a,a,a,j,j,a,a,a,a,
            a,a,a,a,j,j,a,a,a,a,
            a,a,a,a,j,j,a,a,a,a
    };

    drawPixelImage(500, 500, image, 10, 10);

    //drawImage(200,200,biohazard2_XL,128,128);


    drawImage(200,200,biohazard2_XL,128,128);*/
    //shell();
    /*char * strings[] = {"Hola Mundo\n", "echo \"soy Pilo LPMM SOY CRACKK\" \n", "clock -3\n", " \n"};


    for (int i = 0; i < 4; ++i) {
        int state = INITIAL;
        char *string = strings[i];
        int argIndex = 0;
        int letterIndex = 0;
        char argsVector[MAX_ARGS][MAX_ARG_LENGTH]; // vector de punteros a string
        char * c = string;

        while (*c != '\n') //los strings los tenes ue pasar enteros ""
        {
            if (!isGraph(*c)){ // no pued e ser un nombre
                return NULL_CMMD;
            }
            if ((argIndex+1)*(letterIndex+1) > MAX_BUFFER_SIZE){
                return BUFFER_OVERFLOW;
            }
            switch (state){
                case INITIAL:
                    if (isSpace(*c)){
                        state = INITIAL;
                    }else{
                        letterIndex = 0;
                        argsVector[argIndex][letterIndex++] = *c;
                        state = IN_ARGUMENT;
                    }
                    break;
                case SPACE:
                    if(!isSpace(*c)){ // si es espacio nos quedamos aca
                        if (isQuote(*c)){ //string, agrego " porque tal vez eco toma otros parametros
                            state = IN_STRING;
                        }else{
                            state = IN_ARGUMENT;
                        }
                        letterIndex = 0; //empieza un argumento
                        argsVector[argIndex][letterIndex++] = *c;
                    }
                    break;
                case IN_ARGUMENT:
                    if (isSpace(*c)){ // tabs o espacioss etc
                        argsVector[argIndex][letterIndex++] = 0;
                        argIndex++;
                        state = SPACE;
                    }else{
                        argsVector[argIndex][letterIndex++] = *c;
                    }
                    break;
                case IN_STRING:
                    if (isQuote(*c)){
                        state = SPACE;
                    }
                    argsVector[argIndex][letterIndex++] = *c;
            }

            argsVector[argIndex][letterIndex] = 0;
            c++;
        }

        write("Function name: ");
        write(argsVector[0]);
        putChar('\n');
        write("There are: ");
        putChar((char) (argIndex+ '0'));
        write(" arguments.");
        putChar('\n');
        write("They are: ");
        for (int k = 1; k <= argIndex; ++k) {
            write(argsVector[k]);
            write(" ; ");
        }
        putChar('\n');
        putChar('\n');
        //write("Fin1");
    }*/
    //parseAndInterpret("echo hola\n");
    shell();
    //int c = strlen("hola");
    //putChar(c + '0');
    //putChar(c);
    //printf("%s ", "scooby doo papa Y el BOOM BOOM BOOM BOOM BOOM");
    write("Fin2");
    return 0;
}
