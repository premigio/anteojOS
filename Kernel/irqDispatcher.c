#include <stdint.h>
#include "keyboardDriver.h"
#include "videoDriver.h"

static void int_20();

void irqDispatcher(uint64_t irq) {
	//drawString2("irq");
	switch (irq) {
		case 0:
		//drawString2("dio 0");
			//int_20();
			break;
    case 1:
		//drawString2("dio 1");
      keyboardInterpreter();
      break;
	}
	return;
}

void int_20() {
	//timerhandler();
}
