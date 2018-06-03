#include "shell.h"

static Colour fontColour = {255,255,255};
static Colour backColour = {1,1,1};

void shell()
{
    changeFontColour(fontColour);
    changeBackgroundColour(backColour);

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
        NEW_LINE;
        resp = parseAndInterpret(buffer);
        if (resp == EXIT_CMMD){ // modularizar
            run = FALSE;
        } else if(resp == NULL_CMMD){
            printF("%s\n",NO_SUCH_CMMD_MSG);
        } else if (resp == ILLEGAL_INPUT){
            printF("%s\n",ILLEGAL_INPUT_MSG);
        }
        //NEW_LINE;
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

}
void setPresentatonImageCoordinates(int *x, int*y,int width, int height)
{
    unsigned int xRes, yRes;
    getResolutions(&xRes,&yRes);
    *x = xRes/2 - width/2;
    *y = yRes/2 - height/2;
}
void changeFontColour(Colour col)
{
    fontColour = col;
    setFontColour(fontColour);
}
void changeBackgroundColour(Colour col)
{
    backColour = col;
    setBackgroundColour(backColour);
}


