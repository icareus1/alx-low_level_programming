#include<stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - check if the random number is postive, 0 or negative
 * Return: 0 if successful
*/
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
		printf("%d is positive ", n);
	else if (n == 0)
		printf("%d is zero ", n);
	else
		printf("%d is negative ", n);
	return (0);
}
