#include<stdio.h>
#include<ctype.h>
/**
 * main - print hex in lowercase
 * Return: 0 if successful
*/
int main(void)
{
	int ch;

	for (ch = '0'; ch <= '9'; ch++)
	{
		putchar(ch);
	}
	for (ch = 'a'; ch <= 'f'; ch++)
	{
		putchar(ch);
	}
		putchar('\n');
	return (0);
}
