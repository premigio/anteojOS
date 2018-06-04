#include "stdio.h"

void printF(const char * fmt, ... )
{
    va_list arguments;
    va_start(arguments, fmt);
    int length = strlen(fmt);
    int fmtBoolean = 0;
    int j;
    char * aa;

    for (int i=0; i<length; i++)
    {
        if (fmtBoolean == 0)
        {
            if (fmt[i] == '%')
            {
                fmtBoolean=1;
            }
            else
            {
                putChar(fmt[i]);
            }
        }

        else
        {
            switch(fmt[i])
            {
                case 'd':
                    j = va_arg(arguments,int);         //Fetch Decimal/Integer argument
                    if(j<0)
                    {
                        j = -j;
                        putChar('-');
                    }
                    aa= intToAlphaWithBase(j,10);
                    write(aa);
                    break;
                case 's':
                    write((char *)va_arg(arguments, char *));
                    break;
                case 'c':
                    putChar((char)va_arg(arguments, int));
                    break;
                case 'o':
                    j = va_arg(arguments,int);         //Fetch Decimal/Integer argument
                    if(j<0)
                    {
                        j = -j;
                        putChar('-');
                    }
                    aa= intToAlphaWithBase(j,8);
                    write(aa);
                    break;
                case 'x':
                    j = va_arg(arguments,int);         //Fetch Decimal/Integer argument
                    if(j<0)
                    {
                        j = -j;
                        putChar('-');
                    }
                    aa= intToAlphaWithBase(j,16);
                    write(aa);
                    break;
                default:
                    putChar('%');
                    putChar(fmt[i]);
                    break;
            }
            fmtBoolean=0;
        }
    }
    va_end(arguments);
}

char * reaDLine(char * line, unsigned int size)
{
    int i=0;
    char character;
    while (i < size && ( character=getChar() )  != '\n')
    {
        if (character == '\b')
        {
            if (i < size && i != 0)
            {
                i--;
            }
        }
        else if (character != 0)
        {
            if (i < size && i < MAX_BUFFER)
            {
                line[i++] = character;
            }
        }
    }
    line[i]='\n';
    return line;
}

int scanF(char * buffer, unsigned int bufferSize, const char * fmt,...)
{
    va_list args;
    va_start(args, fmt);
    int i = 0;
    char * line = reaDLine(buffer, bufferSize);
    char * c;
    while((*fmt) != '\0')
    {
        if((*fmt) != '%')
        {
            if((*fmt) != (*line))
            {
                va_end(args);
                return i;
            }
            else
            {
                fmt++;
                line++;
            }
        }
        else
        {
            switch(*(++fmt))
            {
                case '%':
                    if(*line != '%')
                    {
                        va_end(args);
                        return 0;
                    }
                    line++;
                    break;
                case 'd':
                    line = toInt(line, va_arg(args,int *), &i);
                    if (i == 0)
                    {
                        va_end(args);
                        return i;
                    }
                    break;
                case 'c':
                    c = va_arg(args, char *);
                    *c = *line++;
                    i++;
                    break;
                case 's':
                    c = va_arg(args, char *);
                    while(*line != '\0')
                    {
                        *c++ = *line++;

                    }
                    i++;
                    break;
            }
            fmt++;
        }
    }
    va_end(args);
    return i;
}

char * toInt(char * string, int * k, int * resp)
{
    *k = 0;
    int sgn = 1, c;
    *resp = 1;
    if (!(*string == '-' || isDigit(*string)))
    {
        *resp = 0;
        return string;
    }
    if(*string == '-')
    {
        if (isDigit(*(string + 1)))
        {
            string++;
            sgn = -1;
            *k = (*string - '0') * sgn;
            string++;
        }
        else
        {
            return string;

        }
    }
    while (isDigit(c = *string))
    {
        *k = (*k) * 10 + (c-'0') * sgn;
        string++;
    }
    return string;
}

char *intToAlphaWithBase(unsigned int n, int base)
{
    static char Representation[]= "0123456789ABCDEF";
    static char buffer[50];
    char *ptr;

    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = Representation[n%base];
        n /= base;
    }while(n != 0);

    return(ptr);
}
