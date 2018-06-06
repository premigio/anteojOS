#ifndef SHELL_H
#define SHELL_H

#include "colour.h"
#include <stdint.h>
#include "video.h"
#include "scLib.h"
#include "clock.h"
#include "shellCommands.h"
#include "stdlib.h"
#include "stdio.h"
#include "eyeGlassesSmall.h"

#define RESET_BUFFER bufferPtr = 0; buffer[0]=0;resp = OK;

#define MIN_SAVER_TIME     10
#define DEFAULT_SAVER_TIME 10

#define OK 1
#define NULL_CMMD -1
#define EXIT_CMMD  -2
#define ILLEGAL_INPUT -3
#define BUFFER_OVERFLOW -4

#define FALSE 0
#define TRUE  1

#define OS_SHELL_LINE     "anteojOS:$ "
#define NO_SUCH_CMMD_MSG  "No such command found, check your input."
#define ILLEGAL_INPUT_MSG "Your input contains illegal values, only printable characters admitted. Check your input."

#define INITIAL      0
#define IN_ARGUMENT  1
#define SPACE        2
#define IN_STRING    4

#define NEW_LINE putChar('\n')

/* runs the shell */
void shell();

/* sets and raws the screen for the shell */
void turnOnOff();

/* sets the coordinates for the presentation logo */
void setPresentatonImageCoordinates(int *, int *,int , int );

/* sets the logo presentation and exits */
void doBeforeExit();

/* interprets the command requested with a given buffer */
int  parseAndInterpret(const char *);

/* prints the formatted shell line */
void printShellLine();

/* clears the screen with a new window*/
void newShell();

/* returns the screen saver status */
int getSaverStatus();

/* sets the screen saver status */
void setSaverStatus(int);

/* returns the saver time */
unsigned int getSaverTime();

/* sets a new saver time */
void setSaverTime(int num);

/* increases the inactivity counter if there is inactivity */
void refreshInactivityCounter();

#endif
