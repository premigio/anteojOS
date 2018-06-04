#ifndef STDIOJIME_H
#define STDIOJIME_H

#include <stdarg.h>
#include "stdlibJime.h"
#include "scLib.h"

#define INT_MAX 2147483647
#define INT_MAXLENGTH 10
#define MAX_BUFFER 1024


void putchar(const char);
void printf(const char *,...);
int scanf(char * buffer, unsigned int bufferSize, const char * fmt, ... );
#endif
