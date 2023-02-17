#include<stdio.h>
#include<ctype.h>
/**
 * main - print double digits
 * Return: 0 if successful
*/
int main(void)
{
	int ch, hc;

	for (ch = 0; ch <= 100; ch++)
	{
		for (hc = ch; hc <= 100; hc++)
		{
			if (ch != hc)
			{
                		putchar(ch / 10 + '0');
                		putchar(ch % 10 + '0');
                		putchar(' ');
                		putchar(hc / 10 + '0');
                		putchar(hc % 10 + '0');
                		if (ch < 98)
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
