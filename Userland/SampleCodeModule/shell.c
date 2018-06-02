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
#define RESET_BUFFER bufferPtr = 0

#define NULL_CMMD 0
#define EXIT_CMMD  -1

#define FALSE 0
#define TRUE  1

#define OS_SHELL_LINE "anteojOS:$ "

#define DEFAULT_TIME_ZONE -3

void shell()
{

    char buffer[MAX_BUFFER_SIZE];
    int bufferPtr;

    int run = TRUE;
    int specialCmmd = NULL_CMMD;

    turnOnOff();
    char c;

    while(run) { // agregar funcionalidad para apretar flecha para arriba
        c = 0;
        RESET_BUFFER;
        printShellLine();
        while(c != '\n'){

            if (newToRead()){
                c = getChar();

                if (isPrintableChar(c)){
                    buffer[bufferPtr++] = c; // bufferPtr siemrpapunta a dpnde agregar
                    putChar(c);
                }else if (c == '\b' && bufferPtr > 0){ // no tendria sentido seguir borrando
                    removeChar();
                    bufferPtr--;
                }else if(c == '\n'){
                    if (bufferPtr > 0){ //sino solamente imprimo una linea nueva pero no mando el comando
                        buffer[bufferPtr] = c; // para que jime sepa hasta donde leer
                        specialCmmd = parseAndInterpret(buffer);
                    } else{
                        putChar(c);
                    }
                }
            }
        }
        if (specialCmmd == EXIT_CMMD){
            run = FALSE;
        }
    }
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

int parseAndInterpret(char *buffer){ // se lee desde indice 0 hasta un \n
  char commandInterpreter[MAX_COMMAND_LENGTH];
  int i = 0;
  int argc = 0;
  char * argv[MAX_BUFFER_SIZE];
  char ant = 0;

  while (*buffer)
  {
    if (*buffer != ' ' && ant == ' ')
    {
      i=0;
      argc++;
      argv[argc][i] = *buffer;
      i++;
    }
    else if ( *buffer != ' ' && ant != ' ')
    {
      argv[argc][i] = *buffer;
      i++;
    }
    buffer++;
    ant = *buffer;
  }

  return getCommand(argc, argv);
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
