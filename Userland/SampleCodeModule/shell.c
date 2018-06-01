#include "include/shell.h"

void shell()
{
    setShell();
    while(1)
    {
        char * string = "Jime sos muy capa!!!";
        write(string);
        //printf("jime sos muy capa");
    }

}

void setShell()
{
    newWindow();
}
