#ifndef STDIOJIME_H
#define STDIOJIME_H

#include <stdarg.h>
#include "stdlibJime.h"
#include "scLib.h"

#define MAX_BUFFER 1024

void printF(const char * fmt, ... );

char * reaDLine(char * line, unsigned int size);

int scanF(char * buffer, unsigned int bufferSize, const char * fmt,...);

char * toInt(char * string, int * k, int * resp);

char *intToAlphaWithBase(unsigned int n, int base);


#endif