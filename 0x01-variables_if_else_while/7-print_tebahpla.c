#include<stdio.h>
#include<ctype.h>
/**
 * main - print alphabets in lowercase
 * Return: 0 if successful
*/
int main(void)
{
	int ch;

	for (ch = 'z'; ch >= 'a'; ch--)
	{
		putchar(tolower(ch));
	}
		putchar('\n');
	return (0);
}
