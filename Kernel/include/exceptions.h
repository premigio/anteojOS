#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

  #define ZERO_EXCEPTION_ID 0
  #define INVALID_OPCODE_ID 6

  #include "sleep.h"

  void exceptionDispatcher(uint64_t exception, uint64_t * rsp);
  static void zeroDivision();
  static void invalidOpcode();
  void printRegisters(uint64_t * rsp);

#endif
