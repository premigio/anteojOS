#ifndef SHELL_H
#define SHELL_H

#define MAX_BUFFER_SIZE 10000
#define MAX_ARGS 10
#define MAX_ARG_LENGTH (MAX_BUFFER_SIZE - (MAX_ARGS) )/MAX_ARGS  // por los espacios
#define RESET_BUFFER bufferPtr = 0

#define NULL_CMMD 0
#define EXIT_CMMD  -1
#define ILLEGAL_INPUT -2
#define BUFFER_OVERFLOW -3

#define FALSE 0
#define TRUE  1

#define OS_SHELL_LINE "anteojOS:$ "
#define NO_SUCH_CMMD_MSG "No such command found, check your input."
#define ILLEGAL_INPUT_MSG "Your input contains illegal values, only printable characters admitted. Check your input."

#define INITIAL      0
#define IN_ARGUMENT  1
#define SPACE        2
#define IN_STRING    4

#define DEFAULT_TIME_ZONE -3

#define NEW_LINE putChar('\n')

typedef char argVector[MAX_ARGS][MAX_ARG_LENGTH];

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
