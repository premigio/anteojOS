#ifndef sysCallHandler_h
#define sysCallHandler_h

#include <stdint.h>

/* saves the registers and makes the system call */
void sysCallHandler(uint64_t i);

#endif
