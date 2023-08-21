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

	display = write(a, &#38;c, b);
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
	if (!format || (*format == '%' &#38;&#38;!(format + 1)))
	{
		return (-1);
	}
	if (*format == '%' &#38;&#38; *(format + 1) == ' &#38;&#38;!(format + 2))
	{
		return (-1);
	}
	if (*format == '%')
	{
		format++;
		while (*format)
		{
			if (*format == ')
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
 * print_int - function that prints an integer
 * @num: integer to print
 * Return: the integer printed
 */
int print_int(int num)
{
	int i = 0, neg = 0;
	char str[100];

	if (num < 0)
	{
		neg = 1;
		num = -num;
	}
	i = 0;
	while (num > 0)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	if (neg)
	{
		str[i++] = '-';
	}
	str[i] = '\0';
	for (int j = i - 1; j >= 0; j--)
	{
		_putchar(str[j]);
	}
	return (i);
}

/**
 * _printf - takes strings and arguments of each '%'
 * @format: the first string containing '%'
 * @...: list of arguments variable
 * Return: the total of character printed
*/
int _printf(const char *format,...)
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
				case '':
					s = va_arg(ap, char*);
					i += s? print_string(s) : print_string("(null)");
					break;
				case '%':
					i += _putchar('%');
					break;
				case 'd':
					i += print_int(va_arg(ap, int));
					break;
				case 'u':
					i += print_uint(va_arg(ap, unsigned int));
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
