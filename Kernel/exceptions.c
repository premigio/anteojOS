#include "videoDriver.h"

#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_ID 6

static void zeroDivision();
static void invalidOpcode();


void exceptionDispatcher(int exception) {
	if (exception == ZERO_EXCEPTION_ID)
		zeroDivision();
	if (exception == INVALID_OPCODE_ID){
		invalidOpcode();
	}
}

static void zeroDivision() {
	drawString("Cannot divide by 0\n");
}

static void invalidOpcode(){
	drawString("No method as such\n");
}
