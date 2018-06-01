#include <stdint.h>
#include "shell.h"
#include "videoModule.h"
#include "colours.h"
#include "stdio.h"
#include "scLib.h"
#include "clock.h"
#include "piloNumbers.h"
#include "biohazard2_XL.h"


#define MAX_BUFFER_SIZE 1000
#define BUFFER_START    0
#define RESET_BUFFER    bufferPtr = BUFFER_START; buffer[0] = 0; // porque hay basura y la primera vez leyendo puede haber un \n

#define NULL_CMMD -1
#define EXIT_CMMD  0

#define FALSE 0
#define TRUE  1

void shell()
{
<<<<<<< HEAD
    char buffer[MAX_BUFFER_SIZE];
    unsigned int bufferPtr;
    RESET_BUFFER;

    int run = TRUE;
    int specialCmmd = NULL_CMMD;

    turnOn();

    while(run) { // agregar funcionalidad para apretar flecha para arriba
        setNewShell();
        while (buffer[bufferPtr] != '\n' ){
            if (newToRead()){
                buffer[bufferPtr] = read();
                putChar(buffer[bufferPtr]);
                bufferPtr++;
                if (bufferPtr == MAX_BUFFER_SIZE){ // me pache
                    RESET_BUFFER;
                }
            }
        }
        if (buffer[bufferPtr] == '\n'){
            specialCmmd = parseAndInterpet(buffer);
            RESET_BUFFER;
        }
        if (specialCmmd == EXIT_CMMD){
            run = FALSE;
        }
    }
    doBeforeExit();
}
=======
    setShell();
    char * string = "Jime sos muy capa!!!";
    write(string);
    //printf("jime sos muy capa");
>>>>>>> parent of daa33c1... asdf

void turnOn(){
    int x, y;
    setPresentatonImageCoordinates(&x,&y,IMAGEWIDTH, IMAGEHEIGHT);
    drawImageFromHexaMap(x, y, biohazard2_XL, IMAGEWIDTH, IMAGEHEIGHT);
    sleep(343);
    sleep(343);
    sleep(343);
    newWindow();
}
void setNewShell()
{
    //newWindow();// -> nose cuando es necesario:
    write("anteojOS:$ ");
}

void doBeforeExit(){
    write("¡Adiós mundo cruel!");
    notifyExitRequest();
}

int parseAndInterpet(char *buffer){ // se lee desde indice 0 hasta un \n
    return 0;
}

void setPresentatonImageCoordinates(int *x, int*y,int width, int height){
    unsigned int xRes, yRes;
    getResolutions(&xRes,&yRes);
    *x = xRes/2 - width/2;
    *y = yRes/2 - height/2;
}
