#include "main.h"
#include<stdlib.h>
/**
 * malloc_checked - allocate memory using malloc
 * @b: the amount to be allocated
 * Return: the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
		exit(98);
	return (ptr);
}
