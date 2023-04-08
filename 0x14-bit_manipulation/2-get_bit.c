#include "main.h"
/**
 * get_bit - returns the value of a bit at a given index
 * @n: the number to retrieve the bit from
 * @index: the index of the bit to be retrieved
 * Return: the bit at the given index, -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);

	if (n > 1 && index > 0)
		return (get_bit(n >> 1, index - 1));

	return (n & 1);
}
