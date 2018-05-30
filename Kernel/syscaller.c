#include <stdint.h>

void syscaller(uint64_t irq, uint64_t rdi/*, uint64_t rsi, uint64_t r9, uint64_t r8*/){//pa dsps si es que quiero color, guia 3
//aca tenemos que poner las funciones de lectura/impresion char etc
  switch (irq) {
    case 1: // WRITE
      drawString((const char *) rdi);
      break;
    case 2:
      //showClock();
      break;
    case 3:
      putChar();
      break;
    case 4:
      getChar((char*) rdi);
      break;
  }
}
