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

#define NULL_CMMD -1
#define EXIT_CMMD  0

#define FALSE 0
#define TRUE  1

#define OS_SHELL_LINE "anteojOS:$ "

void shell()
{

    char buffer[MAX_BUFFER_SIZE];

    int run = TRUE;
    int specialCmmd = NULL_CMMD;

    turnOnOff();

/*    while(run) { // agregar funcionalidad para apretar flecha para arriba

        printShellLine();

    }*/
    doBeforeExit();
}

void turnOnOff(){
    int x, y;
    setPresentatonImageCoordinates(&x,&y,IMAGEWIDTH, IMAGEHEIGHT);
    drawImageFromHexaMap(x, y, biohazard2_XL, IMAGEWIDTH, IMAGEHEIGHT);
    sleep(343);
    sleep(343);
    sleep(343);
    newWindow();
}
void newShell()
{
    newWindow();// -> nose cuando es necesario:
}
void printShellLine()
{
    write(OS_SHELL_LINE);
}
void doBeforeExit(){
    turnOnOff();
    notifyExitRequest();
}

int parseAndInterpet(char *buffer){ // se lee desde indice 0 hasta un \n
    return 1;
}

void setPresentatonImageCoordinates(int *x, int*y,int width, int height){
    unsigned int xRes, yRes;
    getResolutions(&xRes,&yRes);
    *x = xRes/2 - width/2;
    *y = yRes/2 - height/2;
}

int isPrintableChar(char c){
    return c >= 32 && c<=126;
}