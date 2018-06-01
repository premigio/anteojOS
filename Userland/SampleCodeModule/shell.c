#include "shell.h"
#include "videoModule.h"
#include "colours.h"
#include "stdlib.h"
#include "stdio.h"
#include "scLib.h"

void setShell()
{
    //newWindow();
}

void shell()
{
    int run = 1;
    while(run) {
        setShell();
        char *string = "Jime sos muy capa!!!";
        write(string);
        //printf("jime sos muy capa");
    }

}


