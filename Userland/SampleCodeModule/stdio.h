#ifndef STDIO_H
#define STDIO_H

#include <stdarg.h>
#include "stdlib.h"
#include "scLib.h"

#define INT_MAX 2147483647
#define INT_MAXLENGTH 10

void printf(const char *, ...);
int scanf(const char *, ...);

#endif
