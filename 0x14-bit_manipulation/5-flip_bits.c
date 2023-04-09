#include "main.h"
/**
 * flip_bits - counts the number of bits to flip
 * to get from one number to another
 * @n: first number
 * @m: second number
 * Return: the count
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m;
	unsigned int count = 0;

	while (xor > 0)
	{
		count += xor & 1;
		xor >>= 1;
	}
	return (count);
}
