#include "main.h"

/**
 * print_bin - Convert and print an unsigned integer as binary.
 * @args: unsigned integer to be converted.
 *
 * Return: The number of characters printed.
 */
int print_bin(va_list args)
{
	unsigned int n;
	char bin[33];
	int i = 0;

	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		_putchar('0');
		i++;
		return (i);
	}

	while (n > 0)
	{
		bin[i] = (n % 2) + '0';
		n /= 2;
		i++;
	}
	bin[i] = '\0';

	_strrev(bin);
	_puts(bin);

	return (i);
}
