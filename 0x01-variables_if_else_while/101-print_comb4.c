#include<stdio.h>
#include<ctype.h>
/**
 * main - print double digits
 * Return: 0 if successful
*/
int main(void)
{
	int ch, hc;

	for (ch = 0; ch <= 9; ch++)
	{
		for (hc = ch + 1; hc <= 9; hc++)
		{
			for (chc = hc + 1; chc <= 9; chc++)
			{
				putchar(ch + '0');
				putchar(hc + '0');
				putchar(chc + '0');
				if (ch < 7)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
