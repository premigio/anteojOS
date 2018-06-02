#include "shellCommands.h"

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
