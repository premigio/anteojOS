#include "stdioJime.h"

void printF(const char *fmt, ...) {
    va_list arguments;
    va_start(arguments, fmt);
    int length = strlen(fmt);
    int formatBoolean = 0;
    char buffer[INT_MAXLENGTH];


    for (int i = 0; i < length; i++) {
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
                    //putChar('%');
                    putChar(fmt[i]);
                    //putChar(buffer[j]);
                    break;
            }
        }
        va_end(arguments);
    }
}