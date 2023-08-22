#include "main.h"

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
