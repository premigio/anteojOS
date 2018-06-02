#include "shellCommands.h"


int help (int argc, char * argv[]);
int echo (int argc, char * argv[]);
int time (int argc, char * argv[]);
int clear (int argc, char * argv[]);
int beep (int argc, char * argv[]);
int exitShell (int argc, char * argv[]);
int newFontColour (int argc, char * argv[]);

command commands[]={
        {"help", "This command shows the different commands available and their description", help},
        {"echo", "This command shows the content given", echo},
        {"time", "This command displays a clock", time},
        {"clear", "This command clears the screen", clear},
        {"beep", "This command makes a beeping sound", beep},
        {"exitShell", "This command exits the terminal", exitShell},
        {"newFontColour", "This commands sets a new font colour", newFontColour}
};

int help (int argc, char * argv[])
{
    if (argc > 1)
    {
        //printf("%s\n", "Error: illegal argument");
        return 0;
    }
    else
    {
        for (int i=0; i<NUM_COMMANDS; i++)
        {
            //printf("%s\n", commands[i].description);
        }
    }
    return 1;
}

int echo (int argc, char * argv[])
{
    for (int i=0; i<argc; i++)
    {
        //printf("%s ", argv[i]);
    }
    putChar('\n');
    return 1;
}

int time (int argc, char * argv[])
{
    if (argc > 1)
    {
        //printf("%s\n", "Error: illegal argument");
        return 0;
    }
    showClock(TIMEZONE_BSAS);
    return 1;
}

int clear (int argc, char * argv[])
{
    if (argc > 1)
    {
        //printf("%s\n", "Error: illegal argument");
        return 0;
    }
    newShell();
    return 1;
}

int beep (int argc, char * argv[])
{
    if (argc > 1)
    {
        //printf("%s\n", "Error: illegal argument");
        return 0;
    }
    kernelBeep();
    return 1;
}

int exitShell (int argc, char * argv[])
{
    if (argc > 1)
    {
        //printf("%s\n", "Error: illegal argument");
        return 0;
    }
    return -1;
}

int newFontColour(int argc, char * argv[])
{
    if (argc > 1)
    {
        //printf("%s\n", "Error: illegal argument");
        return 0;
    }
    // lo hace pilo
    return 1;
}

int checkCommand(char * name)
{
    for (int i=0; i<NUM_COMMANDS; i++)
    {
        if (1)//(strcmp(name, commands[i]))
        {
            return 1;
        }
    }
    return 0;
}
