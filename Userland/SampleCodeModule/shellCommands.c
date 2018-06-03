#include "shellCommands.h"
<<<<<<< HEAD
#include "stdlibJime.h"

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
        printf("%s\n", HELP_MAX_ARGUMENTS_ERROR);
        return 0;
    }
    else
    {
        for (int i=0; i<NUM_COMMANDS; i++)
        {
            printf("%s: %s\n",commands[i].name ,commands[i].description);
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
                printf("%c", prev);
                prev = argv[i][j++];
            }
            if(!isQuote(prev)){
                printf("%c", prev);
            }
        }else
            {
            printf("%s\n", argv[i]);
        }
    }
    return 1;
}

int time (int argc, argVector argv)
{
    if (argc > 1)
    {
        //printf("%s\n", "Error: illegal argument");
        return 0;
    }
    showClock(TIMEZONE_BSAS);
    return 1;
}

int clear (int argc, argVector argv)
{
    if (argc > 1)
    {
        //printf("%s\n", "Error: illegal argument");
        return 0;
    }
    newShell();
    return 1;
}

int beep (int argc, argVector argv)
{
    if (argc > 1)
    {
        //printf("%s\n", "Error: illegal argument");
        return 0;
    }
    kernelBeep();
    return 1;
}

int exitShell (int argc, argVector argv)
{
    if (argc > 1)
    {
        //printf("%s\n", "Error: illegal argument");
        return 0;
    }
    return -1;
}

int newFontColour(int argc, argVector argv)
{
    if (argc > 1)
    {
        //printf("%s\n", "Error: illegal argument");
        return 0;
    }
    // lo hace pilo
    return 1;
}


=======

int help (int argc, char * argv[]);
int echo (int argc, char * argv[]);
int time (int argc, char * argv[]);
int clear (int argc, char * argv[]);
int beepSound (int argc, char * argv[]);
int exit (int argc, char * argv[]);
int newFontColour (int argc, char * argv[]);

command commands[]={
  {"help", "This command shows the different commands available and their description", help},
  {"echo", "This command shows the content given", echo},
  {"time", "This command displays a clock", time},
  {"clear", "This command clears the screen", clear},
  {"beep", "This command makes a beeping sound", beepSound},
  {"exit", "This command exits the terminal", exit}
  {"newFontColour", "This commands sets a new font colour", newFontColour}
};

int help (int argc, char * argv[])
{
  if (argc > 1)
  {
    printf("%s\n", "Error: illegal argument");
    return 0;
  }
  else
  {
    for (int i=0; i<NUM_COMMANDS; i++)
    {
      printf("%s\n", commands[i].description);
    }
  }
  return argc;
}

int echo (int argc, char * argv[])
{
  for (int i=0; i<argc; i++)
  {
    printf("%s ", argv[i]);
  }
  putchar('\n');
  return argc;
}

int time (int argc, char * argv[])
{
  if (argc > 1)
  {
    printf("%s\n", "Error: illegal argument");
    return 0;
  }
  showClock();
  return argc;
}

int clear (int argc, char * argv[])
{
  if (argc > 1)
  {
    printf("%s\n", "Error: illegal argument");
    return 0;
  }
  newShell();
  return argc;
}

int beepSound (int argc, char * argv[])
{
  if (argc > 1)
  {
    printf("%s\n", "Error: illegal argument");
    return 0;
  }
  beep();
  return argc;
}

int exit (int argc, char * argv[])
{
  if (argc > 1)
  {
    printf("%s\n", "Error: illegal argument");
    return 0;
  }
  return -1;
}

int newFontColour(int argc, char * argv[])
{
  if (argc > 1)
  {
    printf("%s\n", "Error: illegal argument");
    return 0;
  }
  // lo hace pilo
  return argc;
}

int checkCommand(char * name)
{
  for (int i=0; i<NUM_COMMANDS; i++)
  {
    if (strcmp(name, commands[i].name) == 0)
    {
      return 1;
    }
  }
  return 0;
}

int getCommand(char * name, int argc, char * argv[])
{
  if (!checkCommand(name))
  {
    return 0;
  }
  for (int i=0; i<NUM_COMMANDS && !found; i++)
  {
    if (strcmp(name, commands[i].name) == 0)
    {
        return commands[i].fn(argc, argv);
    }
  }
  return 0;
}
>>>>>>> 9e8c5d02cb9548bea75372b6786ab2f7ed9debcf
