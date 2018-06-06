#include "shell.h"

static int screenSaverStatus = TRUE;
static unsigned int saverTime = DEFAULT_SAVER_TIME;
static unsigned int inactivityCounter = 0;
int secs = 0;

void shell()
{
    char buffer[MAX_BUFFER_SIZE];
    int bufferPtr;
    int run = TRUE;
    int resp = NULL_CMMD;
    char c;
    turnOnOff();
    while(run)
    {
        c = 0;
        RESET_BUFFER;
        printShellLine();
        while(c != '\n')
        {
            refreshInactivityCounter();
            if (inactivityCounter >= saverTime && screenSaverStatus)
            {
                showClock(SCREEN_SAVER_MODE);
                inactivityCounter = 0;
                newShell();
                printShellLine();
            }
            if (newToRead())
            {
                inactivityCounter = 0;
                c = getChar();
                if (isGraph(c))
                {
                    buffer[bufferPtr++] = c;      // bufferPtr siempre apunta a donde agregar
                    putChar(c);
                }
                else if (c == '\b' && bufferPtr > 0)  // no tendria sentido seguir borrando
                {
                    removeChar();
                    bufferPtr--;
                }
                else if(c == '\n')
                {
                    if (bufferPtr > 0)    //sino solamente imprimo una linea nueva pero no mando el comando
                    {
                        buffer[bufferPtr] = c; // para saber hasta donde leer
                        NEW_LINE;
                        resp = parseAndInterpret(buffer);
                    }
                    else
                    {
                        putChar(c);
                    }
                }
            }
        }
        if (resp == EXIT_CMMD)
        {
            run = FALSE;
        }
        else if(resp == NULL_CMMD)
        {
            printF("%s\n", NO_SUCH_CMMD_MSG);
        }
        else if (resp == ILLEGAL_INPUT)
        {
            printF("%s\n",ILLEGAL_INPUT_MSG);
        }
    }
    doBeforeExit();
}

void turnOnOff()
{
    int x, y;
    kernelBeep();
    newWindow();
    changeFontColour(getCurrentFontColour());
    changeBackgroundColour(getCurrentBackgroundColour());
    setPresentatonImageCoordinates(&x,&y,GLASSESWIDTH, GLASSESWIDTH);
    drawImageFromHexaMap(x, y, eyeGlassesSmall, GLASSESWIDTH, GLASSESHEIGHT);
    sleep();
    sleep();
    sleep();
    sleep();
    sleep();
    newWindow();
}

void newShell()
{
    newWindow();
}

void printShellLine()
{
    printF("%s",OS_SHELL_LINE);
}

void doBeforeExit()
{
    turnOnOff();
    notifyExitRequest();
}

int parseAndInterpret(const char *string) // se lee desde indice 0 hasta un \n
{
    int spaceFlag = 0;
    int state = INITIAL;
    int argIndex = 0;
    int letterIndex = 0;
    argVector argsVector; // vector de punteros a string
    argsVector[0][0] = 0;
    char * c = (char *) string;

    while (*c != '\n') //los strings se pasan enteros enteros ""
    {
        if (!isGraph(*c) && *c != 0)// no puede ser un nombre, tiene que ser distinto de 0 porque reseteamos el primer indice del buffer
        {
            return NULL_CMMD;
        }
        if ((argIndex+1)*(letterIndex+1) > MAX_BUFFER_SIZE)
        {
            return BUFFER_OVERFLOW;
        }
        switch (state)
        {
            case INITIAL:
                if (isSpace(*c))
                {
                    state = INITIAL;
                    spaceFlag = 1;
                }
                else
                {
                    letterIndex = 0;
                    argsVector[argIndex][letterIndex++] = *c;
                    state = IN_ARGUMENT;
                    spaceFlag = 0;
                }
                break;
            case SPACE:
                if(!isSpace(*c))      // si es espacio nos quedamos aca
                {
                    if (spaceFlag) {
                      argIndex++;
                    }
                    if (isQuote(*c))    //string, agrego " porque tal vez echo toma otros parametros
                    {
                        state = IN_STRING;
                    }
                    else
                    {
                        state = IN_ARGUMENT;
                    }
                    letterIndex = 0;         //empieza un argumento
                    argsVector[argIndex][letterIndex++] = *c;
                }
                break;
            case IN_ARGUMENT:
                if (isSpace(*c))        // tabs o espacioss etc
                {
                    argsVector[argIndex][letterIndex++] = 0;
                    spaceFlag++;
                    state = SPACE;
                }
                else
                {
                    argsVector[argIndex][letterIndex++] = *c;
                }
                break;
            case IN_STRING:
                if (isQuote(*c))
                {
                    state = SPACE;
                }
                argsVector[argIndex][letterIndex++] = *c;
        }

        argsVector[argIndex][letterIndex] = 0;
        c++;
    }
    if(argsVector[0][0] == 0){
        return OK;
    }
    return executeCommand(argIndex+1, argsVector);
}

void setPresentatonImageCoordinates(int *x, int*y,int width, int height)
{
    unsigned int xRes, yRes;
    getResolutions(&xRes,&yRes);
    *x = xRes/2 - width/2;
    *y = yRes/2 - height/2;
}

int getSaverStatus()
{
    return screenSaverStatus;
}

unsigned int getSaverTime()
{
    return saverTime;
}

void setSaverStatus(int flag)
{
    screenSaverStatus = flag;
}

void refreshInactivityCounter()
{
    int s = getSecond();
    if(getSecond()!= secs)
    {
        inactivityCounter++;
        secs = s;
    }
}

void setSaverTime(int num)
{
    saverTime = num;
}

