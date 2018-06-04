#ifndef STDLIB_H
#define STDLIB_H

#define LINE_SIZE 256

/* returns a given integer to a string containing that integer */
unsigned intToAlpha(long , char * , unsigned );

/* returns a given unsigned integer to a string containing that integer */
unsigned unsignedToAlpha(unsigned long , char * , unsigned );

/* returns a given double to a string containing that double */
void doubleToAlpha(double , char * , unsigned );

/* returns the length of a given string */
int strlen(const char *);

/* returns a boolean if the given char corresponds to a digit */
int isDigit(char);

/*
** returns a positive number if the first string is greater than the second one
** returns a negative number if the first string is lower than the second one
** returns 0 if the strings are equal
*/
int strcmp(char *, char *);

/* returns a boolean if the given character represents a space (in ascii) */
int isSpace(char );

/* returns a boolean if the given character represents a graph (in ascii) */
int isGraph(char );

/* returns a boolean if the given character represents a quote (in ascii) */
int isQuote(char );

#endif
