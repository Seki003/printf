#include "main.h"
#include <stddef.h>

/**
 * _printf - it is a cloning of printf func
 * @format: the text that should be printed
 * @...: more arguments
 * Returns: number of char printed
*/

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, k = 0, count = 0;
	char *word = NULL;

	va_start(args, format);
	while (format[i])
	{
		if (format[i++] == '%')
		{
			if (format[i] == '%')
				putchar('%'), i++;
			else if (format[i] == 'c')
				putchar(va_arg(args, int)), i++;
			else if (format[i] == 's')
			{
				word = va_arg(args, char*);
				while (putchar(word[k++]));
				i++;
			}
		}
		else
			putchar(format[i - 1]);
		count++;
	}
	va_end(args);
	return (count);
}
