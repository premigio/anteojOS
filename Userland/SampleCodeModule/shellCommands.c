#include "shellCommands.h"


command commands[NUM_COMMANDS]={
        {"help",  "Shows the different commands available and their description.", help},
        {"echo",  "Prints on stdout the specified string/s. Strings without quotes are considered separated", echo},
        {"time",  "Prints the current system time with default Timezone. Timezone can be changed with 'timezone' command", time},
        {"clear", "Clears the screen.", clear}, //agregar funcionalidad para flecha para arriba y control c
        {"beep",  "Requests kernel to emit beep from motherboard.", beep},
        {"exit", "Exits the terminal.", exitShell},
        {"font_colour", "Changes the font colour.", font_colour},
        {"background_colour", "Changes the background colour.", background_colour},
        {"digital_clock","Displays a digital clock on screen", digital_clock},
        //{"timezone", "Allows the user to change the current timezone",timezone}
};

int executeCommand(int argc, argVector argv)
{
    int cmd = commandExists(argv[0]);
    if (cmd == NULL_CMMD)
    {
        return NULL_CMMD;
    }
    return (*commands[cmd].fn)(argc,argv);
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
    return NULL_CMMD;
}
int help (int argc, argVector argv)
{
    if (argc > 1)
    {
        printF("%s\n", CERO_ARGUMENTS_ERROR);
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
            NEW_LINE;
        }
        else
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
        printF("%s\n", CERO_ARGUMENTS_ERROR);
        return 0;
    }
    printF("Current time: %d:%d:%d\n", getTimezoneHour(), getMinute(), getSecond());
    return 1;
}
int clear (int argc, argVector argv)
{
    if (argc > 1)
    {
        printF("%s\n", CERO_ARGUMENTS_ERROR);
        return 0;
    }
    newShell();
    return 1;
}
int beep (int argc, argVector argv)
{
    if (argc > 1)
    {
        printF("%s\n", CERO_ARGUMENTS_ERROR);
        return 0;
    }
    kernelBeep();
    return 1;
}
int exitShell (int argc, argVector argv)
{
    if (argc > 1)
    {
        printF("%s\n", CERO_ARGUMENTS_ERROR);
        return 0;
    }
    return EXIT_CMMD;
}
int font_colour(int argc, argVector argv)
{
    if (argc > 1)
    {
        printF("%s\n", CERO_ARGUMENTS_ERROR);
        return 0;
    }
    changeColour(changeFontColour);
    return 1;
}
int background_colour(int argc, argVector argv)
{
    if (argc > 1)
    {
        printF("%s\n", CERO_ARGUMENTS_ERROR);
        return 0;
    }
    int changed = changeColour(changeBackgroundColour);
    if (changed)
    {
        clear(argc,argv);
    }
    return 1;
}
int changeColour(void(*f)(Colour) )
{
    Colour original = getCurrentFontColour();
    printF("%s\n", SET_FONT_MSSG);
    for (int i = 0; i < COLOURS_AMOUNT; ++i) {
        changeFontColour(userColours[i]);
        printF("%d) %s \n", i, SET_FONT_EX );
    }
    changeFontColour(original);
    char c;
    int ask = TRUE;
    int changed = FALSE;
    while (ask){
        if (newToRead()){
            c = getChar();
            if (isDigit(c)){
                (*f)(userColours[c-'0']);
                ask = FALSE;
                changed = TRUE;
            }else if(c == 'q'){
                ask = FALSE;
            }
        }
    }
    return changed;
}
int digital_clock(int argc, argVector argv)
{
    if (argc > 1)
    {
        printF("%s\n", CERO_ARGUMENTS_ERROR);
        return 0;
    }
    showClock();
    clear(argc,argv);
    return 1;
}

