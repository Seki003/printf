#include "main.h"
#include <stddef.h>

/**
 * print_string - func that print a string after specifier %
 * @word: pointer to char string
 *
 * Return: formatted strings
*/

int print_string(char *word)
{
	int k = 0;

	while (word[k])
	{
		putchar(word[k]);
		k++;
	}
	return (k);
}

/**
 * _printf - print the input and deal with '%'
 * @format: include the string putted and entered
 * @...: list of arguments variable
 * Return: the total of character printed
*/

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	char *word = NULL;
	int count = 0;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case '%':
                    putchar('%');
                    count++;
                    break;
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    i++;
                    word = va_arg(args, char *);
                    print_string(word);
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(format[i]);
                    count += 2;
                    break;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
			i++;
		}
	}

	va_end(args);
	return (count);
}
