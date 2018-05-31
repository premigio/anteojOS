#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

  #define ZERO_EXCEPTION_ID 0
  #define INVALID_OPCODE_ID 6

  void exceptionDispatcher(uint64_t exception, uint64_t * rsp);
  static void zeroDivision(uint64_t * rsp);
  static void invalidOpcode(uint64_t * rsp);
  void printRegisters(uint64_t * rsp);

#endif
