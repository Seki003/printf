#include "main.h"

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
