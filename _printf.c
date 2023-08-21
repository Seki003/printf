#include "main.h"
#include <stddef.h>

/**
 * _printf - take text as input and print it, clone printf
 * @format: containts the strings and char
 * @...: arguments entered
 * Return: the number of char printed
*/

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int k = 0;
	char *word = NULL;
	int count = 0;

	va_start(args, format);

	while (format[i] != '\0')
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
				count =+ print_str(word);
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
