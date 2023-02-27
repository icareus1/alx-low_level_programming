#include "main.h"
/**
 * puts2 - print only one character out of two starting with the first one
 * @str: input
 */
void puts2(char *str)
{
	int length = 0;
	char *s = str;
	int i;

	while (*s != '\0')
	{
		s++;
		length++;
	}
	length--;
	for (i = 0 ; i <= length ; i++)
	{
		if (i % 2 == 0)
			_putchar(str[i]);
	}
	_putchar('\n');
}

