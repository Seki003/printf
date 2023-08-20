#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format)
    {
        if (*format == '%' && format++)
        {
            if (*format == 'c')
                putchar(va_arg(args, int)), count++;
            else if (*format == 's')
                for (char *str = va_arg(args, char *); putchar(*str++); count++);
            else if (*format == '%')
                putchar('%'), count++;
            else
                putchar('%'), putchar(*format), count += 2;
        }
        else
            putchar(*format), count++;

        format++;
    }

    va_end(args);
    return count;
}
