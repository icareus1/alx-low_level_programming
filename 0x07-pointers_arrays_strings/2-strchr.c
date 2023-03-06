#include "main.h"
/**
 * _strchr - trim string starting from a given character
 * @s: string
 * @c: where to start trimming
 * Return: trimmed string
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] >= '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
}
