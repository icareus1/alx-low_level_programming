#include<stdio.h>
#include<ctype.h>
/**
 * main - print nums in lowercase
 * Return: 0 if successful
*/
int main(void)
{
	int ch, hc;

	for (ch = 0; ch <= 9; ch++)
	{
		for (hc = 1; hc <= 9; hc++)
		{
			if (ch != hc)
			{
				putchar(ch + '0');
				putchar(hc + '0');
			}
				putchar(',');
				putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
