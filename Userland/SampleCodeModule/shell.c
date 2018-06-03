#include <stdint.h>
#include "shell.h"
#include "videoModule.h"
#include "colours.h"
#include "stdio.h"
#include "scLib.h"
#include "clock.h"
#include "piloNumbers.h"
#include "biohazard2_XL.h"
#include "shellCommands.h"
#include "stdlibJime.h"

void shell()
{
    char buffer[MAX_BUFFER_SIZE];
    int bufferPtr;

    int run = TRUE;
    int resp = NULL_CMMD;

    turnOnOff();
    char c;

    while(run) { // agregar funcionalidad para apretar flecha para arriba
        c = 0;
        RESET_BUFFER;
        printShellLine();
        while(c != '\n'){

            if (newToRead()){
                c = getChar();

                if (isGraph(c)){
                    buffer[bufferPtr++] = c; // bufferPtr siemrpapunta a dpnde agregar
                    putChar(c);
                }else if (c == '\b' && bufferPtr > 0){ // no tendria sentido seguir borrando
                    removeChar();
                    bufferPtr--;
                }else if(c == '\n'){
                    if (bufferPtr > 0){ //sino solamente imprimo una linea nueva pero no mando el comando
                        buffer[bufferPtr] = c; // para que jime sepa hasta donde leer
                    } else{
                        putChar(c);
                    }
                }
            }
        }
        resp = parseAndInterpret(buffer);
        if (resp == EXIT_CMMD){ // modularizar
            run = FALSE;
        } else if(resp == NULL_CMMD){
            NEW_LINE;
            write(NO_SUCH_CMMD_MSG);
        } else if (resp == ILLEGAL_INPUT){
            NEW_LINE;
            write(ILLEGAL_INPUT_MSG);
        }
        NEW_LINE;
    }
    doBeforeExit();
}
void turnOnOff()
{
    int x, y;
    setPresentatonImageCoordinates(&x,&y,IMAGEWIDTH, IMAGEHEIGHT);
    drawImageFromHexaMap(x, y, biohazard2_XL, IMAGEWIDTH, IMAGEHEIGHT);
    sleep();
    sleep();
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
void doBeforeExit()
{
    turnOnOff();
    notifyExitRequest();
}
int parseAndInterpret(const char *string)// se lee desde indice 0 hasta un \n
{
    int state = INITIAL;
    int argIndex = 0;
    int letterIndex = 0;
    argVector argsVector; // vector de punteros a string
    char * c = (char *) string;

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

<<<<<<< HEAD
        argsVector[argIndex][letterIndex] = 0;
        c++;
    }
    /*write("Function name: ");
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
    }*/
    //putChar('\n');
    //putChar('\n');
    //write("Entrado a execute Command");
    //putChar('\n');
    int resp = executeCommand(argIndex+1, argsVector);
    //write("saliendo de execute Command");
    //putChar('\n');
    return resp;
=======
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
>>>>>>> 9e8c5d02cb9548bea75372b6786ab2f7ed9debcf
}
void setPresentatonImageCoordinates(int *x, int*y,int width, int height)
{
    unsigned int xRes, yRes;
    getResolutions(&xRes,&yRes);
    *x = xRes/2 - width/2;
    *y = yRes/2 - height/2;
}

<<<<<<< HEAD
=======
int isPrintableChar(char c){
    return c >= 32 && c<=126;
}
>>>>>>> 9e8c5d02cb9548bea75372b6786ab2f7ed9debcf
