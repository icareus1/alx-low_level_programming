#include<stdio.h>
/**
 * main - print alphabets in lowercase
 * Return: 0 if successful
*/
char main(void)
{
	char c;

	for (c = 'a'; c <= 'z'; ++c)
	{
		putchar(c);
		putchar("\n");
	}
	return (0);
}