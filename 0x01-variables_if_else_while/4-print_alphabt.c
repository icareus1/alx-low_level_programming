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
		if (ch == 'q' || ch == 'e')
			continue;
		else
			putchar(tolower(ch));
	}
		putchar('\n');
	return (0);
}
