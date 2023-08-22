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
