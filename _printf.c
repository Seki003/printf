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
		_putchar(word[k]);
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
				print_string(word = va_arg(args, char *));
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
