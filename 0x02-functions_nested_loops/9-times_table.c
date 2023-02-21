#include "main.h"

/**
 * times_table - self explanatory
 */
void times_table(void)
{
	int i, j, x;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			x = i * j;
			if (x < 10 && x != 0)
			{
				_putchar(x + '0');
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
			}
			if (x >= 10)
			{
				_putchar((x / 10) + '0');
				_putchar((x % 10) + '0');
				_putchar(',');
				_putchar(' ');
			}
		}
			_putchar('\n');
	}
}
