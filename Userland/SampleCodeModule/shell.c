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

    char string[MAX_BUFFER_SIZE];
    int stringPtr;

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
                    string[stringPtr++] = c; // stringPtr siemrpapunta a dpnde agregar
                    putChar(c);
                }else if (c == '\b' && stringPtr > 0){ // no tendria sentido seguir borrando
                    removeChar();
                    stringPtr--;
                }else if(c == '\n'){
                    if (stringPtr > 0){ //sino solamente imprimo una linea nueva pero no mando el comando
                        string[stringPtr] = c; // para que jime sepa hasta donde leer
                        resp = parseAndInterpret(string);
                        newShell();
                    } else{
                        putChar(c);
                    }
                }
            }
        }
        if (resp == EXIT_CMMD){
            run = FALSE;
        } else if(resp == NULL_CMMD){
            putChar('\n');
            write(NO_SUCH_CMMD_MSG);
            putChar('\n');
        } else if (resp == ILLEGAL_INPUT){
            putChar('\n');
            write(ILLEGAL_INPUT_MSG);
            putChar('\n');
        }
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
int parseAndInterpret(const char *string)
{ // se lee desde indice 0 hasta un \n
    int state = INITIAL;
    int argIndex = 0;
    int letterIndex = 0;
    char argsVector[MAX_ARGS][MAX_ARG_LENGTH]; // vector de punteros a string
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
                    state = SPACE;
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
    return 0;//executeCommand();
}

void setPresentatonImageCoordinates(int *x, int*y,int width, int height){
    unsigned int xRes, yRes;
    getResolutions(&xRes,&yRes);
    *x = xRes/2 - width/2;
    *y = yRes/2 - height/2;
}
