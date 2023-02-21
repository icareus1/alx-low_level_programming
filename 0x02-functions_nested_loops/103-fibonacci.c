#include <stdio.h>
/**
 * main - Prints sum of even fibnoacci nums under 4,000,000.
 * Return: Always 0.
 */
int main(void)
{
	int num1 = 1, num2 = 2, sum = 0, even_sum = 0;

	while (num2 <= 4000000)
	{
		sum = num1 + num2;
		num1 = num2;
		num2 = sum;
		if (num1 % 2 == 0)
		{
			even_sum += num1;
		}
	}
	printf("%d\n", even_sum);
	return (0);
}
