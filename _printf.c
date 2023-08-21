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
	char *s, c;
	char *word = NULL;
	int count = 0;

	va_start(args, format);

	if (check(format) == -1)
		return (-1);

	while (format[i])
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
				s = va_arg(args, char *);
				i += s ? print_str(s) : print_str("(null)");
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
