#include "shellCommands.h"

command commands[NUM_COMMANDS]={
        {"help",  "Shows the different commands available and their description.", help},
        {"echo",  "Prints on stdout the specified string/s. Strings without quotes are considered separated", echo},
        {"time",  "Prints the current system time with default Timezone. Timezone can be changed with 'timezone' command", time},
        {"clear", "Clears the screen.", clear},
        {"beep",  "Requests kernel to emit beep from motherboard.", beep},
        {"exit", "Exits the terminal.", exitShell},
        {"font_colour", "Changes the font colour.", font_colour},
        {"background_colour", "Changes the background colour.", background_colour},
        {"digital_clock","Displays a digital clock on screen", digital_clock},
        {"timezone", "Allows the user to change the current timezone. Usage: timezone [int]",timezone},
        {"screen_saver", "Allows user to change screen savers parameters. Input on/off to turn on/off, or a positive integer to change waiting time.", screen_saver},
        {"exceptionTester", "This command calls an exception,0 for zero division, 1 for Invalid Opcode", exceptionTester}
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
    if (argc == 1)
    {
        return 0;
    }
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
            if(!isQuote(prev))
            {
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
    changeColour(changeFontColour, FONT);
    return 1;
}

int background_colour(int argc, argVector argv)
{
    if (argc > 1)
    {
        printF("%s\n", CERO_ARGUMENTS_ERROR);
        return 0;
    }
    int changed = changeColour(changeBackgroundColour, BACK);
    if (changed)
    {
        clear(argc,argv);
    }
    return 1;
}

int changeColour(void(*f)(Colour), int flag)
{
    Colour original = getCurrentFontColour();
    printF("%s\n", SET_FONT_MSSG);
    for (int i = 1; i <= COLOURS_AMOUNT; ++i)
    {
        changeFontColour(userColours[i]);
        printF("%d) %s \n", i, SET_FONT_EX );
    }
    changeFontColour(original);
    char c;
    int ask = TRUE;
    int changed = FALSE;
    Colour c1 = getCurrentFontColour();
    Colour c2 = getCurrentBackgroundColour();
    while (ask)
    {
        if (newToRead())
        {
            c = getChar();
            if (c >= '1' && c <= '9')
            {
                Colour col = userColours[c-'0'];
                if ((equalColour(col, c1) && flag == BACK)|| (equalColour(col, c2) && flag == FONT))
                {
                  printF("Choose another colour, one that makes everything better! \n");
                }
                else
                {
                  (*f)(col);
                  ask = FALSE;
                  changed = TRUE;
                }
            }
            else if(c == 'q')
            {
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
    showClock(NORMAL_MODE);
    clear(argc,argv);
    return 1;
}

int timezone(int argc, argVector argv)
{
    if (argc != 2)
    {
        printF("%s\n", ARGUMENTS_AMOUNT_ERROR("1"));
        return 0;
    }
    int flag = 0;
    int num = 0;
    toInt(argv[1],&num,&flag);
    if(flag)
    {
        changeTimeZone(num);
        printF("%s %d\n", TIMEZONE_SUCCES_MSG, num);
        time(0,argv);
    }
    else
    {
        printF("%s\n", TIMEZONE_ERROR_MSG);
    }
    return 1;
}

int screen_saver(int argc, argVector argv)
{
    if (argc != 2)
    {
        printF("%s\n", ARGUMENTS_AMOUNT_ERROR("1"));
        printF("Change waiting time in seconds by passing an integer greater than %d.\n", MIN_SAVER_TIME);
        printF("Screen saver is currently %s.\n", (getSaverStatus()? "on":"off"));
        printF("Turn it %s by passing '%s'.\n", (!getSaverStatus()? "on":"off"),  (!getSaverStatus()? "on":"off"));
        return 0;
    }
    if(strcmp(argv[1],"on"))
    {
        setSaverStatus(TRUE);
        printF("Screen saver is now %s, and will wait %d seconds\n", (getSaverStatus()? "on":"off"), getSaverTime());
    }
    else if(strcmp(argv[1],"off"))
    {
        setSaverStatus(FALSE);
        printF("Screen saver is now %s.\n", (getSaverStatus()? "on":"off"));
    }
    else
    {
        int flag = 0;
        int num = 0;
        toInt(argv[1],&num,&flag);
        if(flag && num > MIN_SAVER_TIME)
        {
            setSaverTime(num);
            printF("Screen saver will now wait %d seconds\n", getSaverTime());
        }
        else
        {
            printF("Waiting time must be an integer greater than %d.\n", MIN_SAVER_TIME);
            return 0;
        }
    }
    return 1;
}

int exceptionTester(int argc, argVector argv)
{
  if (argc > 2)
  {
      printF("%s\n", CERO_ARGUMENTS_ERROR);
      return 0;
  }
  else if (strcmp(argv[1],"0"))
  {
    zeroDivisionException();
  }
  else if(strcmp(argv[1],"1"))
  {
    invalidOpcodeException();
  }
  else
  {
    printF("Wrong arguments\n");
  }
  return 1;
}
