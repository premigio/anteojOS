#include "shellCommands.h"

int help (int argc, argVector argv);
int echo (int argc, argVector argv);
int time (int argc, argVector argv);
int clear (int argc, argVector argv);
int beep (int argc, argVector argv);
int exitShell (int argc, argVector argv);
int set_font_colour (int argc, argVector argv);
int set_backgroud_colour(int argc, argVector argv);
int set_backgroud_colour(int argc, argVector argv);

#define CERO_ARGUMENTS_ERROR "Too many arguments passed, function takes 0 arguments"
#define SET_FONT_MSSG "Choose a colour by typing a number."
#define SET_FONT_EX "This is a colour example."

#define NUM_COMMANDS 8 //<----------
command commands[NUM_COMMANDS]={
        {"help",  "Shows the different commands available and their description.", help},
        {"echo",  "Prints on stdout the specified string/s. Strings without quotes are considered separated", echo},
        {"time",  "Prints the current system time with default Timezone. Timezone can be changed with 'timezone' command", time},
        {"clear", "Clears the screen.", clear}, //agregar funcionalidad para flecha para arriba y control c
        {"beep",  "Requests kernel to emit beep from motherboard.", beep},
        {"exitShell", "Exits the terminal.", exitShell},
        {"set_font_colour", "Changes the font colour.", set_font_colour},
        {"set_background_colour", "Changes the background colour.", set_background_colour}
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
    printF("Current time: %d:%d:%d", getHour(), getMinute(), getSecond());
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
int set_font_colour(int argc, argVector argv)
{
    if (argc > 1)
    {
        printF("%s\n", CERO_ARGUMENTS_ERROR);
        return 0;
    }
    printF("%s\n", SET_FONT_MSSG);
    for (int i = 0; i < COLOURS_AMOUNT; ++i) {
        changeFontColour(userColours[i]);
        //printF("%d) %s \n", i+1, SET_FONT_EX );
        write("Colour reflect your personality!");
        NEW_LINE;
    }
    char c;
    int ask = 1;
    while (ask){
        if (newToRead()){
            c = getChar();
            if (isDigit(c)){
                changeFontColour(userColours[c-'0']);
                ask = 0;
            }
        }
    }
    return 1;
}
int set_backgroud_colour(int argc, argVector argv)
{
    if (argc > 1)
    {
        printF("%s\n", CERO_ARGUMENTS_ERROR);
        return 0;
    }
    printF("%s\n", SET_FONT_MSSG);
    for (int i = 0; i < COLOURS_AMOUNT; ++i) {
        changeFontColour(userColours[i]);
        //printF("%d) %s \n", i+1, SET_FONT_EX );
        write("Colour reflect your personality!");
        NEW_LINE;
    }
    char c;
    int ask = 1;
    while (ask){
        if (newToRead()){
            c = getChar();
            if (isDigit(c)){
                changeBackgroundColour(userColours[c-'0']);
                ask = 0;
            }
        }
    }
    return 1;
}

