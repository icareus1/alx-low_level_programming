#include<stdio.h>
/**
 * main - print numbers up to 10
 * Return: 0 if successful
*/
int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
	{
		putchar(num + '0');
	}
		putchar('\n');
	return (0);
}
