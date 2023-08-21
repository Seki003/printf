#include "main.h"

/**
 * print_string - func that print a string after specifier %
 * @word: pointer to char string
 *
 * Return: formatted strings
*/

int print_str(char *word)
{
	int k = 0;

	while (word[k])
	{
		_putchar(word[k]);
		k++;
	}
	return (k);
}
