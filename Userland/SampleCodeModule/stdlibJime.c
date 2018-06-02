#include "stdlibJime.h"

unsigned unsignedToAlpha(unsigned long number, char * buffer, unsigned base)
{
    char * p = buffer;
    char * p1;
    char * p2;
    unsigned digits = 0;
    do
    {
        unsigned remainder = number % base;
        *p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
        digits++;
    }
    while (number /= base);

    *p = 0;
    p1 = buffer;
    p2 = ((char *)(p-1));

    while (p1 < p2)
    {
        char aux = *p1;
        *p1 = *p2;
        *p2 = aux;
        p1++;
        p2--;
    }
    return digits;
}

unsigned intToAlpha(long number, char * buffer, unsigned base)
{
    int aux = 0;
    if (number < 0)
    {
        number = -number;
        buffer[0] = '-';
        buffer++;
        aux++;
    }
    return aux + unsignedToAlpha(number, buffer, base);
}

void doubleToAlpha(double value, char * buffer, unsigned base)
{
    long castedValue = (long) value;
    unsigned dim = intToAlpha(castedValue, buffer, base);
    buffer[dim++] = '.';

    double decimals = value - castedValue;
    decimals = (decimals < 0) ? -decimals : decimals;

    for(int i = 0; i < 5; i++)
    {
        decimals *= base;
        castedValue = decimals;
        unsigned remainder = castedValue % base;
        buffer[dim++] = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
    }
}

int strLEN(const char *string)
{
    int i=0;
    while (string[i] != '\n')
    {
        i++;
    }
    return i;
}

int isDigit(char c)
{
    return c>='0' && c<='9' ? 1 : 0 ;
}

int strCMP(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
        {
            return 0;
        }
        s1++;
        s2++;
    }
    if (*s1 == 0 && *s2!=0)
    {
        return 0;
    }
    else if (*s1!=0 && *s2==0)
    {
        return 0;
    }
    return 1;
}
