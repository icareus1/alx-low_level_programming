#include<stdio.h>
/**
 * main - print alphabets in lowercase
 * Return: 0 if successful
*/
int main(void)
{
	int c;

	for (c = 'a'; c <= 'z'; ++c)
	{
		char low = tolower(c);
		putchar(low);
		putchar("\n");
	}
	return (0);
}
