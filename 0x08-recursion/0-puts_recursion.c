#include "main.h"
/**
 * _puts_recursion - function like puts() and prints string;
 * @s: the string
 */
void _puts_recursion(char *s)
{
	if (*s != "\0")
	{
		_putchar(*s);
		s++;
		_puts_recursion(s);
	}

	else
		_putchar('\n');
}
