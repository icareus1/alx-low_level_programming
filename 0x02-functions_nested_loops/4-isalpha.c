#include "main.h"
/**
 * _isalpha - check if element is an alphabet
 * @c: character to be checked
 * Return: 1 if an alpha, else 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
