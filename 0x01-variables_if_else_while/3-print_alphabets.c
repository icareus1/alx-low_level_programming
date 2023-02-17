#include<stdio.h>
#include<ctype.h>
/**
 * main - print alphabets in lowercase
 * Return: 0 if successful
*/
int main(void)
{
	int ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar(tolower(ch));
	}
	for (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar(toupper(ch));
	}
		putchar('\n');
	return (0);
}
