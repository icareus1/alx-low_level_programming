#include "main.h"
/**
 * _strstr - return a substring
 * @haystack: string
 * @needle: substring
 * Return: 0 if successful
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *str = haystack;
		char *p = needle;

		while (*str == *p && *p != '\0')
		{
			str++;
			p++;
		}

		if (*p == '\0')
			return (haystack);
	}

	return (0);
}
