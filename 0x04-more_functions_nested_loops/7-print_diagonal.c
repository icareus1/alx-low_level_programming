#include "main.h"
/**
 * print_diagonal - draws a diagonal line in the terminal
 * @n: how long you want the line to be
 */
void print_diagonal(int n)
{
	if (n <= 0)
		_putchar('\n');
	else
	{
		int i;

		for (i = 1; i <= n; i++)
		{
			_putchar('\\');
		}
		_putchar('\n');
	}
}
