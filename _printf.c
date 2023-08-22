#include "main.h"
#include <stddef.h>

/**
 * format_c - A function that checks the format
 * @format: A pointer to a string
 * Return: -1
 */
int format_c(const char *format)
{
	if (!format || (*format == '%' && !(format + 1)))
	{
		return (-1);
	}
	if (*format == '%' && *(format + 1) == ' ' && !(format + 2))
	{
		return (-1);
	}
	if (*format == '%')
	{
		format++;
		while (*format)
		{
			if (*format == ' ')
			{
				format++;
				continue;
			}
			return (0);
		}
		return (-1);
	}
	return (0);
}

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
	char *word = NULL;
	int count = 0;

	va_start(args, format);

	if (format_c(format) == -1)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				count += _putchar('%');
			}
			else if (format[i] == 'c')
			{
				count += _putchar(va_arg(args, int));
			}
			else if (format[i] == 's')
			{
				word = va_arg(args, char *);
				if (word == NULL)
            		word = "(null)";
				count += print_str(word);
			}
			else
			{
				if (format[i] == '\0')
					return (-1);
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}
	
	va_end(args);
	return (count);
}
