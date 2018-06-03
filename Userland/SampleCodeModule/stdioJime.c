#include "stdioJime.h"

<<<<<<< HEAD
void printf(const char *fmt, ...)
=======
void putchar(char c)
{
    char aux [2];
    aux[0] = c;
    aux[1] = '\0';
    write(aux);
}

void printf(const char * fmt, ... )
>>>>>>> 9e8c5d02cb9548bea75372b6786ab2f7ed9debcf
{
    va_list arguments;
    va_start(arguments, fmt);
    int length = strlen(fmt);
    int formatBoolean = 0;
    char buffer[INT_MAXLENGTH];
<<<<<<< HEAD

    for (int i = 0; i < length; i++)
    {
        if (formatBoolean == 0) {
            if (fmt[i] == '%') {
                formatBoolean = 1;
            } else {
                putChar(fmt[i]);

            }
        } else {
            switch (fmt[i]) {
                case 'd':
                    intToAlpha(va_arg(arguments,int), buffer, 10);
                    for (int j = 0; buffer[j] != '\n'; j++) {
                        putChar(buffer[j]);
                    }
                    break;
                case 's':
                    write(va_arg(arguments,char *));
                    break;
                case 'c':
                    putChar((char) va_arg(arguments,int));
                    break;
                case 'g':
                     /*doubleToAlpha(va_arg(arguments, double), buffer, 10);
                     for (int i3=0; buffer[i3] != '\n'; i3++)
                     {
                         putChar(buffer[i3]);
                     }*/
                      // NO ANDA
                    break;
                case 'o':
                    intToAlpha(va_arg(arguments,int), buffer, 8);
                    for (int j = 0; buffer[j] != '\n'; j++) {
                        putChar(buffer[j]);
                    }
                    break;
                case 'x':
                    intToAlpha(va_arg(arguments,int), buffer, 16);
                    for (int j = 0; buffer[j] != '\n'; j++) {
                        putChar(buffer[j]);
                    }
                    break;
                default:
                    putChar('%');
                    putChar(fmt[i]);
                    //putChar(buffer[j]);
                    break;
            }
            formatBoolean = 0;
=======
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
>>>>>>> 9e8c5d02cb9548bea75372b6786ab2f7ed9debcf
        }
    }
    va_end(arguments);
}

<<<<<<< HEAD

/*int scanf(const char *fmt, ...) {
=======
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
>>>>>>> 9e8c5d02cb9548bea75372b6786ab2f7ed9debcf
    va_list arguments;
    va_start(arguments, fmt);

    int length = 0;
<<<<<<< HEAD
    char *line = readLine();
    int *number;
    char *string;
    int i = 0;
    int j = 0;

    while (fmt[i] != '\n') {
        if (fmt[i] != '%') {
            if ((fmt[i]) != (line[j])) {
                return length;
            } else {
                i++;
                j++;
            }
        } else {
            i++;
            switch (fmt[i]) {
                case 'd':
                    number = va_arg(arguments,int *);
                    *number = 0;
                    while (isDigit(line[j])) {
                        *number = (*number) * 10 + (line[j] - '0');
=======
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
>>>>>>> 9e8c5d02cb9548bea75372b6786ab2f7ed9debcf
                        j++;
                    }
                    length++;
                    break;
                case 's':
<<<<<<< HEAD
                    string = va_arg(arguments,char*);
                    char c;
                    while ((c = line[j]) != '\n') {
=======
                    string = va_arg(arguments, char*);
                    char c;
                    while( (c = line[j]) != '\n' )
                    {
>>>>>>> 9e8c5d02cb9548bea75372b6786ab2f7ed9debcf
                        *string = c;
                        string++;
                        j++;
                    }
                    length++;
                    break;
                case 'c':
<<<<<<< HEAD
                    string = va_arg(arguments,char*);
=======
                    string = va_arg(arguments, char*);
>>>>>>> 9e8c5d02cb9548bea75372b6786ab2f7ed9debcf
                    *string = line[j];
                    j++;
                    length++;
                    break;
                default:
<<<<<<< HEAD
                    if (line[j] != '%') {
=======
                    if (line[j] != '%')
                    {
>>>>>>> 9e8c5d02cb9548bea75372b6786ab2f7ed9debcf
                        return length;
                    }
                    j++;
                    break;
            }
            i++;
        }
    }
<<<<<<< HEAD
    return length;
}*/
 
=======

    return length;
}
>>>>>>> 9e8c5d02cb9548bea75372b6786ab2f7ed9debcf
