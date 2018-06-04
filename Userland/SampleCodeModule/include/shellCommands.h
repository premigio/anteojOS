#include <stdint.h>
#include "stdlib.h"
#include "stdio.h"
#include "clock.h"
#include "shell.h"
#include "scLib.h"

#define NUM_COMMANDS 4
typedef struct
{
    char * name;
    char * description;
    int (* fn) (int argc, char * argv[]);
} command;

int commandExists(char *);
int executeCommand(int argc, char * argv[]);

extern void zeroDivisionException();
extern void invalidOpcodeException();