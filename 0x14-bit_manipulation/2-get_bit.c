#include "main.h"
/**
 * get_bit - returns the value of a bit at a given index
 * @n: the number to retrieve the bit from
 * @index: the index of the bit to be retrieved
 * Return: the bit at the given index, -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int bit_at_ind;

	if (index > 63)
		return (-1);

	bit_at_ind = (n >> index) & 1;
	return (bit_at_ind);
}
