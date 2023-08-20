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
				putchar('%');
				count++;
				i++;
			}
			else if (format[i] == 'c')
			{
				putchar(va_arg(args, int));
				count++;
				i++;
			}
			else if (format[i] == 's')
			{
				i++;
				word = va_arg(args, char *);
				k = 0;
				while (word[k] != '\0')
				{
					putchar(word[k]);
					count++;
					k++;
				}
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
