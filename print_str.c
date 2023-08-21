#include "main.h"

/**
 * print_string - func that print a string after specifier %
 * @word: pointer to char string
 *
 * Return: formatted strings
*/

void print_str(char *word)
{
	int i = 0;

	while (word[i] != '\0')
	{
		_putchar(word[i]);
		word++;
	}
	return (i);
}
