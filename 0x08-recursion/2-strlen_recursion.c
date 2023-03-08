#include "main.h"
/**
 * _strlen_recursion - string length
 * @s: string
 * Return: string length
 */
int _strlen_recursion(char *s)
{
	if (*s)
		return (1 + _strlen_recursion(s + 1));
}
