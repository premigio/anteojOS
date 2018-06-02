
#include <stdarg.h>
#include "scLib.h"
#include "stdlibJime.h"
#include "stdioJime.h"
/*

void printf(const char * fmt, ... )
{
    va_list arguments;
    va_start(arguments, fmt);
    int length = strlen(fmt);
    int formatBoolean = 0;
    char buffer[INT_MAXLENGTH];
    for (int i=0; i<length; i++)
    {
        if (formatBoolean == 0)
        {
            if (fmt[i] == '%')
            {
                formatBoolean=1;
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
                    intToAlpha(va_arg(arguments, int), buffer, 10);
                    for (int i1 = 0; buffer[i1] != '\n'; i1++)
                    {
                        putChar(buffer[i1]);
                    }
                    break;
                case 's':
                    write(va_arg(arguments, char *));
                    break;
                case 'c':
                    putChar((char)va_arg(arguments, int));
                    break;
                case 'g':
                     doubleToAlpha(va_arg(arguments, double), buffer, 10);
                    for (int i3=0; buffer[i3] != '\n'; i3++)
                    {
                        putChar(buffer[i3]);
                    }
                    break;// NO ANDA
                default:
                    putChar('%');
                    putChar(fmt[i]);
                    break;
            }
            formatBoolean=0;
        }
    }
    va_end(arguments);
}

int scanf(const char * fmt, ... )
{
    va_list arguments;
    va_start(arguments, fmt);

    int length = 0;
    char * line = readLine();
    int * number;
    char * string;
    int i = 0;
    int j = 0;

    while(fmt[i] != '\n')
    {
        if(fmt[i]!='%')
        {
            if((fmt[i]) != (line[j]))
            {
                return length;
            }
            else
            {
                i++;
                j++;
            }
        }

        else
        {
            i++;
            switch( fmt[i] )
            {
                case 'd':
                    number = va_arg(arguments, int *);
                    *number = 0;
                    while( isDigit(line[j]) )
                    {
                        *number = (*number)*10 + (line[j] - '0');
                        j++;
                    }
                    length++;
                    break;
                case 's':
                    string = va_arg(arguments, char*);
                    char c;
                    while( (c = line[j]) != '\n' )
                    {
                        *string = c;
                        string++;
                        j++;
                    }
                    length++;
                    break;
                case 'c':
                    string = va_arg(arguments, char*);
                    *string = line[j];
                    j++;
                    length++;
                    break;
                default:
                    if (line[j] != '%')
                    {
                        return length;
                    }
                    j++;
                    break;
            }
            i++;
        }
    }

    return length;
}

*/
