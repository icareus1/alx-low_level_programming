#include<stdio.h>
#include<stdarg.>
#include "variadic_functions.h"
/**
 * sum_them_all - Returns the sum of its args
 * @n: The number of args to be passed to the function.
 * @...: a certain number of args.
 * Return: 0 If n == 0 else the sum
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i, sum = 0;

	if (n == 0)
		return (0);

	va_start(args, n);
	for (i = 0; i < n; i++)
		sum += va_arg(args, int);
	va_end(args);
	return (sum);
}
