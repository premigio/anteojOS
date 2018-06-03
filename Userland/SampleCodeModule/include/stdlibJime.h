#ifndef STDLIBJIME_H
#define STDLIBJIME_H

#define LINE_SIZE 256

unsigned intToAlpha(long number, char * buffer, unsigned base);
unsigned unsignedToAlpha(unsigned long number, char * buffer, unsigned base);
void doubleToAlpha(double value, char * buffer, unsigned base);
int strlen(const char *string);
int isDigit(char);
int strcmp(char *a, char *b);
int isSpace(char c);
int isGraph(char c);
int isQuote(char c);

#endif
