#ifndef _idtLoader_H_
#define _idtLoader_H_

#include <stdint.h>
#include <defs.h>
#include <interrupts.h>
#include <sysCallHandler.h>

/* loads the interrupt handlers to de idt */
void loadIDT();

#endif
