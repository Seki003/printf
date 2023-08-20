#include "main.h"
#include <stddef.h>

/**
 * _printf - take text as input and print it, clone printf
 * @format: containts the strings and char
 * @...: arguments entered for the func
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
