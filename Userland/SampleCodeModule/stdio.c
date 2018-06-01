#include "include/stdio.h"

void putchar(const char c)
{
    write(&c);
}

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
                putchar(fmt[i]);
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
                        putchar(buffer[i1]);
                    }
                    break;
                case 's':
                    write(va_arg(arguments, char *));
                    /*for (int i2=0; string[i2] != '\n'; i2++)
                    {
                        putchar(string[i2]);
                    }*/
                    break;
                case 'c':
                    putchar((char)va_arg(arguments, int));
                    break;
                case 'g':
                   /* doubleToAlpha(va_arg(arguments, double), buffer, 10);
                    for (int i3=0; buffer[i3] != '\n'; i3++)
                    {
                        putchar(buffer[i3]);
                    }
                    break;*/ // NO ANDA
                default:
                    putchar('%');
                    putchar(fmt[i]);
                    break;
            }
            formatBoolean=0;
        }
    }
    va_end(arguments);
}

char * readLine()
{
    int i, character;
    char line[LINE_SIZE];
    while (( character=read() )  != '\n')
    {
        if (character == '\b')
        {
            if (i != 0)
            {
                i--;
            }
        }
        else
        {
            if (i < LINE_SIZE)
            {
                line[i++] = character;
            }
            putchar(character);
        }
    }
    putchar(character);
    line[i]='\n';
    return line;
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