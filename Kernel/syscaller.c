#include <stdint.h>

void syscaller(uint64_t irq, uint64_t rdi){
//aca tenemos que poner las funciones de lectura/impresion char etc
  switch (irq) {
    case 1:
      drawString((const char *) rdi);
      break;
  }
}
