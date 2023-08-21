#include "main.h"

/**
 * print_string - func that print a string after specifier %
 * @word: pointer to char string
 *
 * Return: formatted strings
*/

int print_str(char *word)
{
	int i = 0;

	while (word[i] != '\0')
	{
		_putchar(word[i]);
		i++;
	}
	return (i);
}
