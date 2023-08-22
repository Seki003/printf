#include "main.h"

/**
 * print_unsigned - the func printing unsind int
 * @types: arguments entered
 * @buffer: the buffer that handle print
 * @flags:  seeing and calculates flags
 * @width: getting the width
 * @precision: specification and precisionn
 * @size: the specifier of size
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - printing an unsigend number in octal
 * @types: arguments entered
 * @buffer: the buffer that handle print
 * @flags:  seeing and calculates flags
 * @width: getting the width
 * @precision: specification and precisionn
 * @size: the specifier of size
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - printing an unsined number with hexadecimal
 * @types: arguments entered
 * @buffer: the buffer that handle print
 * @flags:  seeing and calculates flags
 * @width: getting the width
 * @precision: specification and precisionn
 * @size: the specifier of size
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - printing the unsinged int in hexadecimal format
 * @types: arguments entered
 * @buffer: the buffer that handle print
 * @flags:  seeing and calculates flags
 * @width: getting the width
 * @precision: specification and precisionn
 * @size: the specifier of size
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: arguments entered
 * @map_to: Array of values to map the number to
  * @buffer: the buffer that handle print
 * @flags:  calculating flags that are active
 * @flag_ch: Calculates active flags with ch
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: specification of the size
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
