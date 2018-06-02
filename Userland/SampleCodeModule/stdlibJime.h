#ifndef STDLIB_H
#define STDLIB_H

#define LINE_SIZE 256

unsigned intToAlpha(long number, char * buffer, unsigned base);
unsigned unsignedToAlpha(unsigned long number, char * buffer, unsigned base);
void doubleToAlpha(double value, char * buffer, unsigned base);
int strlen(const char *);
int isDigit(char);
int strcmp(char *, char *);

#endif
