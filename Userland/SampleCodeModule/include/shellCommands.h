#ifndef SHELLCOMMANDS_H
#define SHELLCOMMANDS_H

#include "colour.h"
#include <stdint.h>
#include "clock.h"
#include "shell.h"
#include "scLib.h"
#include "stdlibJime.h"
#include "stdioJime.h"
#include "timezone.h"

#define MAX_BUFFER_SIZE 10000
#define MAX_ARGS 10
#define MAX_ARG_LENGTH (MAX_BUFFER_SIZE - (MAX_ARGS) )/MAX_ARGS  // por los espacios

#define CERO_ARGUMENTS_ERROR  "Too many arguments passed, function takes 0 arguments"
#define SET_FONT_MSSG         "Choose a colour by typing a number, or press 'q' exit."
#define SET_FONT_EX           "Colours reflect your personality!"
#define TIMEZONE_MSG1         "Current timezone is: "
#define TIMEZONE_MSG2         "Input the desired timezone: "
#define TIMEZONE_ERROR_MSG    "Only numbers and '-' are allowed in timezone format. Please re-enter your timezone:"

#define NUM_COMMANDS 9 //<----------


typedef char argVector[MAX_ARGS][MAX_ARG_LENGTH];

typedef struct
{
    char * name;
    char * description;
    int (* fn) (int argc, argVector argv);
} command;

int commandExists(const char *);
int executeCommand(int argc, argVector argv);
int changeColour(void(*f)(Colour) );

int help (int argc, argVector argv);
int echo (int argc, argVector argv);
int time (int argc, argVector argv);
int clear(int argc, argVector argv);
int beep (int argc, argVector argv);
int exitShell (int argc, argVector argv);
int font_colour (int argc, argVector argv);
int background_colour(int argc, argVector argv);
int digital_clock(int argc, argVector argv);
//int timezone(int argc, argVector argv);


#endif
