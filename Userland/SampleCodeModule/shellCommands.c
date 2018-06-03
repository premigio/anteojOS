#include "shellCommands.h"

#define NO_SUCH_CMMD_INDEX -1

int help (int argc, argVector argv);
int echo (int argc, argVector argv);
int time (int argc, argVector argv);
int clear (int argc, argVector argv);
int beep (int argc, argVector argv);
int exitShell (int argc, argVector argv);
int newFontColour (int argc, argVector argv);

command commands[]={
        {"help", "Shows the different commands available and their description.", help},
        {"echo", "Prints on stdout the specified string/s. Strings without quotes are considered separated", echo},
        {"time", "Prints the current system time with default Timezone: . Timezone can be changed with 'timezone' command", time},
        {"clear", "This command clears the screen.", clear},
        {"beep", "This command makes a beeping sound.", beep},
        {"exitShell", "This command exits the terminal.", exitShell},
        {"newFontColour", "This commands sets a new font colour.", newFontColour}
};

int executeCommand(int argc, argVector argv)
{
    //write("In ExectueCOmmand recibimos:");
    //write((char *) argv[0]);
    int cmd = commandExists(argv[0]);

    if (cmd == NO_SUCH_CMMD_INDEX){
        //write("NO such Command");
        return NO_SUCH_CMMD_INDEX;
    }
    //write("Command FOund");
    return (*commands[cmd].fn)(argc,argv); //jfjhgjhgjhghjg
}
int commandExists(const char *name)
{
    for (int i=0; i<NUM_COMMANDS; i++)
    {
        if (strcmp((char *) name, commands[i].name))
        {
            return i;
        }
    }
    write("no such COmmand found");
    return NO_SUCH_CMMD_INDEX;
}
#define HELP_MAX_ARGUMENTS_ERROR "help: Too many arguments passed, help takes 0 arguments"
int help (int argc, argVector argv)
{
    if (argc > 1)
    {
        printF("%s\n", HELP_MAX_ARGUMENTS_ERROR);
        return 0;
    }
    else
    {
        for (int i=0; i<NUM_COMMANDS; i++)
        {
            printF("%s: %s\n",commands[i].name ,commands[i].description);
        }
    }
    return 1;
}

int echo (int argc, argVector argv)
{
    NEW_LINE;
    for (int i=1; i<argc; i++)
    {
        if (isQuote(argv[i][0]))
        {
            char prev = argv[i][1];
            int j=2;
            while (argv[i][j])
            {
                printF("%c", prev);
                prev = argv[i][j++];
            }
            if(!isQuote(prev)){
                printF("%c", prev);
            }
        }else
            {
            printF("%s\n", argv[i]);
        }
    }
    return 1;
}

int time (int argc, argVector argv)
{
    if (argc > 1)
    {
        //printF("%s\n", "Error: illegal argument");
        return 0;
    }
    showClock(TIMEZONE_BSAS);
    return 1;
}

int clear (int argc, argVector argv)
{
    if (argc > 1)
    {
        //printF("%s\n", "Error: illegal argument");
        return 0;
    }
    newShell();
    return 1;
}

int beep (int argc, argVector argv)
{
    if (argc > 1)
    {
        //printF("%s\n", "Error: illegal argument");
        return 0;
    }
    kernelBeep();
    return 1;
}

int exitShell (int argc, argVector argv)
{
    if (argc > 1)
    {
        //printF("%s\n", "Error: illegal argument");
        return 0;
    }
    return -1;
}

int newFontColour(int argc, argVector argv)
{
    if (argc > 1)
    {
        //printF("%s\n", "Error: illegal argument");
        return 0;
    }
    // lo hace pilo
    return 1;
}

