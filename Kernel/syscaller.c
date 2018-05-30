#include <stdint.h>
#define NFUNCTIONS 5

// void (*fList)[NFUNCTIONS] = {getChar, putChar};

void syscaller(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8/*,  uint64_t r9*/){//pa dsps si es que quiero color, guia 3
//aca tenemos que poner las funciones de lectura/impresion char etc
  // void (*function)(uint64_t rsi);
  // function = fList[rdi];
  // function(rsi);

  switch (rdi) {
    case 1: // WRITE
      drawString((const char *) rsi);
      break;
    case 2:
      //showClock();
      break;
    case 3:
      putChar();
      break;
    case 4:
      getChar((char*) rsi);
      break;
    case 5:
      *((unsigned int*)rsi) = getHour();
      break;
    case 6:
      *((unsigned int*)rsi) = getMin();
      break;
    case 7:
      *((unsigned int*)rsi) = getSec();
      break;
    case 8:
      drawClock( (char *)rsi, (int)rdx, (int)rcx, (int)r8 );
      break;
    case 9:
      beep();
      break;
  }
}
