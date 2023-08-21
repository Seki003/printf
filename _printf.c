#include "main.h"

/**
 * print_char - fucnction that prints a char character
 * @a: file descriptor integer to output
 * @c: character parameter/
 * @b: character size
 * Return: the character
 */
int print_char(int a, int c, int b)
{
	int display;

	display = write(a, &c, b);
	return (display);
}

/**
 * print_string - Function which prints string
 * @str_char: pointer to char string
 *
 * Return: formatted strings
*/

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                {
                    char *str = va_arg(args, char *);
                    while (*str)
                    {
                        putchar(*str);
                        count++;
                        str++;
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    if (num < 0)
                    {
                        putchar('-');
                        count++;
                        num = -num;
                    }
                    int temp = num, digits = 0;
                    while (temp)
                    {
                        temp /= 10;
                        digits++;
                    }
                    temp = digits;
                    while (digits--)
                    {
                        int power = 1;
                        for (int i = 1; i < temp; i++)
                            power *= 10;
                        putchar('0' + (num / power));
                        num %= power;
                        temp--;
                        count++;
                    }
                    break;
                }
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}
