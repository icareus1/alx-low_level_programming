#include "main.h"
/**
 * _strlen_recursion - string length
 * @s: string
 * Return: string length
 */
int _strlen_recursion(char *s)
{
	int i;

	i = 0;
	if (*s)
	{
		i++;
		_strlen_recursion(s);
		_putchar(i + '0');
	}
	return (*s);
}
