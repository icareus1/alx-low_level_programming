#include <stdlib.h>
#include "main.h"
/**
 * _memset - fills memory with a constant byte
 * @a: memory area to be filled
 * @x: char to copy
 * @n: number of times to copy x
 * Return: pointer to the memory area a
 */
char *_memset(char *a, char x, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		a[i] = x;
	return (a);
}

/**
 * _calloc - allocates memory for an array
 * @nmemb: number of elements in the array
 * @size: size of each element
 * Return: allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return (NULL);
	_memset(ptr, 0, nmemb * size);
	return (ptr);
}
