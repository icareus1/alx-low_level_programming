#include "main.h"
/**
 * puts_half - a function that prints half of a string
 * if odd len, n = (length_of_the_string - 1) / 2
 * @str: input
 */
void puts_half(char *str)
{
	int i, n, length;
	
	while (*str != "\0")
	{
		length++;
		str++;
	}
	if ((length % 2) == 1)
		n = ((length - 1) / 2);
	else
		n = (length / 2);
	for (i = n; *str != "\0"; i++)
		_putchar(str[i]);
	_putchar('\n');
}
