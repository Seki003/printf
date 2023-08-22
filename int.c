#include "main.h"

/**
 * _printint - Prints an int using _putint
 * @args: Argument list containing ints to print
 *
 * Return: int printed by _putint
 */
int _printint(va_list args)
{
	int n;

	n = va_arg(args, int);
	return (_putint(n));
}
