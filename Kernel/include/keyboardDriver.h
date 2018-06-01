#ifndef _keyboardDriver_h
#define _keyboardDriver_h
  extern int getKey(void);
  void keyboardInterpreter();
  void charToBuffer(unsigned char c);
  char returnNextChar();
  int newToRead();
#endif
