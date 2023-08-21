#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
int _printf(const char *format, ...)
{
    int count = 0;
    int i = 0;
    int k = 0;
    char *word;
    va_list args;
    va_start(args, format);
    while (format[i]!= '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '%')
            {
                _putchar('%');
                count++;
                i++;
            }
            else if (format[i] == 'c')
            {
                _putchar(va_arg(args, int));
                count++;
                i++;
            }
            else if (format[i] == 's')
            {
                i++;
                word = va_arg(args, char *);
                while (word[k]!= '\0')
                {
                    _putchar(word[k]);
                    count++;
                    k++;
                }
                _putchar(' ');
                count++;
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
            i++;
        }
    }
    va_end(args);
    return (count);
}
