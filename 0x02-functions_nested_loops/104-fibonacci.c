#include <stdio.h>
/**
 * main - prints the first 98 Fibonacci numbers
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int prev = 0, curr = 1, next, count;

	for (count = 1; count <= 98; count++)
	{
		printf("%lu", curr);
		if (count != 98)
		printf(", ");
		next = prev + curr;
		prev = curr;
		curr = next;
	}
	printf("\n");
	return (0);
}
