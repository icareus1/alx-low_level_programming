#include "main.h"
/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to the number to modify
 * @index: index of the bit
 * Return: 1 if successful, or -1 if not
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= 63)
		return (-1);

	*n &= ~(1 << index);
	return (1);
}