#ifndef STDLIBJIME_H
#define STDLIBJIME_H

#define LINE_SIZE 256

unsigned intToAlpha(long number, char * buffer, unsigned base);
unsigned unsignedToAlpha(unsigned long number, char * buffer, unsigned base);
void doubleToAlpha(double value, char * buffer, unsigned base);
int strLEN(const char *string);
int isDigit(char);
int strCMP(char *a, char *b);

#endif
