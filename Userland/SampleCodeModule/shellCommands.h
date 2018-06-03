#ifndef SHELLCOMMANDS_H
#define SHELLCOMMANDS_H

#include <stdint.h>
#include "stdlib.h"
#include "stdio.h"
#include "clock.h"
#include "shell.h"
#include "scLib.h"
#include "stdlibJime.h"
#include "stdioJime.h"

#define MAX_BUFFER_SIZE 10000
#define MAX_ARGS 10
#define MAX_ARG_LENGTH (MAX_BUFFER_SIZE - (MAX_ARGS) )/MAX_ARGS  // por los espacios

#define NUM_COMMANDS 5 //<----------

typedef char argVector[MAX_ARGS][MAX_ARG_LENGTH];

typedef struct
{
    char * name;
    char * description;
    int (* fn) (int argc, argVector argv);
} command;

int commandExists(const char *);
int executeCommand(int argc, argVector argv);

#endif
