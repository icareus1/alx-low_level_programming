#include "main.h"
/**
 * _puts - print a string
 * @str: contains the string
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		printf("%s", *str);
		str++;
	}
}
