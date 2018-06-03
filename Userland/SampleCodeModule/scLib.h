#ifndef SCLIB_H
#define SCLIB_H

#include <stdint.h>
#include "colours.h"

void write(char * string);
char getChar();
int getHour();
int  getMinute();
int  getSecond();
void kernelBeep();
void timeElapsed();
void sleep();
void userDrawPixel(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);
void getResolutions(unsigned int * rdi, unsigned int * rsi);
void setFontColour(Colour colour);
void printImage(unsigned int rdi, unsigned int rsi, const unsigned short *rdx, unsigned int rcx, unsigned int r8);
int  newToRead();
int notifyExitRequest();
void newWindow();
int putChar(char c);
int removeChar();
void setBackgroundColour(Colour colour);

#endif
