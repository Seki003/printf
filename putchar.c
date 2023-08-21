#include "main.h"

/**
 * _putchar - printing the argument given
 * @c: Characters intered to be printed
 * Return: 1 on success and elso on not success
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
