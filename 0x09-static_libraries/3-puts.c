#include "main.h"
#include<stdio.h>
/**
 * _puts - print a string
 * @str: contains the string
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		printf("%c", *str);
		str++;
	}
	printf("\n");
}
