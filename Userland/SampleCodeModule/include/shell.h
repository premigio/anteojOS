#ifndef SHELL_H
#define SHELL_H

#include "colour.h"
#include <stdint.h>
#include "videoModule.h"
#include "scLib.h"
#include "clock.h"
#include "biohazard2_XL.h"
#include "shellCommands.h"
#include "stdlibJime.h"
#include "stdioJime.h"

#define RESET_BUFFER bufferPtr = 0

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

void shell();
void turnOnOff();
void setPresentatonImageCoordinates(int *x, int*y,int width, int height);
void setNewShell();
void doBeforeExit();
int  parseAndInterpret(const char *buffer);
int  isGraph(char c);
void printShellLine();
void newShell();



#endif
