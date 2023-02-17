#include<stdio.h>
#include<ctype.h>
/**
 * main - print nums in lowercase
 * Return: 0 if successful
*/
int main(void)
{
	int ch;

	for (ch = 0; ch <= 9; ch++)
	{
		putchar(ch + '0');
		for (int hc = 1; hc <=9; hc++)
		{
			if (ch != hc)
			{
				putchar(hc + '0');
				putchar(',');
				putchar(' ');
			}
	}
		putchar('\n');
	return (0);
}
