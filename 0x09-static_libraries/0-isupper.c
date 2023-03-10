#include "main.h"
/**
 * _isupper -  whether it is uppercase or not.
 * @c: variable
 * Return: 1 is true, 0 if false
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
