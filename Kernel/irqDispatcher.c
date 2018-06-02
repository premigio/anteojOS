#include <stdint.h>
#include "keyboardDriver.h"
#include "videoDriver.h"
#include "timeDriver.h"

static void int_20();
static void int_21();

void irqDispatcher(uint64_t irq) {
	switch (irq) {
		case 0:
			drawChar('h');
			int_20();
			break;
		case 1:
			int_21();
			break;
	}
	return;
}

void int_20() {
    //drawChar('s');
	timerHandler();
	//drawChar('h');
}

void int_21() {
	keyboardInterpreter();
}
