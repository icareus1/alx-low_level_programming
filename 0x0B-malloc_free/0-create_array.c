#include "main.h"
#include<stdlib.h>
/**
 * create_array - a string initialized with a specific char
 * @size: size of the array
 * @c: character
 * Return: a pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *s;
	int i;

	s = malloc(sizeof(char) * size);
	if (size == 0)
		return (NULL);
	for (i = 0; i<size; i++)
		s[i] = c;
	return (s);
}
