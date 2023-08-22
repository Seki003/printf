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
int print_string(char *str_char)
{
	int i = 0;

	while (*str_char)
	{
		_putchar(*str_char);
		str_char++;
		i += 1;
	}
	return (i);
}

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
 * _printf - takes strings and arguments of each '%'
 * @format: the first string containing '%'
 * @...: list of arguments variable
 * Return: the total of character printed
*/
int _printf(const char *format, ...)
{
	char c, *s;
	int i = 0;
	va_list ap;

	va_start(ap, format);
	if (format_c(format) == -1)
		return (-1);
	if (format)
	{
		while (*format)
		{
			if (*format == '%')
			{
				format++;
				switch (*format)
				{
				case 'c':
					c = va_arg(ap, int);
					i += _putchar(c);
					break;
				case 's':
					s = va_arg(ap, char*);
					i += s ? print_string(s) : print_string("(null)");
					break;
				case '%':
					i += _putchar('%');
					break;
				default:
					i += _putchar('%') + _putchar(*format);
					break;
			}
			}
			else
				i += _putchar(*format);
			format++;
			}
		}
		va_end(ap);
		return (i);
	}
