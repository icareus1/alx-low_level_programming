#include "main.h"
/**
 * _strncpy - copy a string
 * @dest: destination string
 * @src: source string
 * @n: num of bytes to copy
 * Return: copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n && *src != '\0')
	{
		*dest = *src;
		i++;
		dest++;
		src++;
	}
	dest++;
	*dest = '\0';
	return (dest);
}
