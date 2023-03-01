#include "main.h"
/**
 * string_toupper - change all lowercase to uppercase
 * @s: the string value
 * Return: the string after the change
 */
char *string_toupper(char *s)
{
	int i, j;

	j = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		while (s[i] >= 'a' && s[i] <= 'z')
		{
			while (s[j] >= 'A' && s[j] <= 'Z')
			{
				if (s[i] == s[j])
					s[i] = s[j];
				j++;
			}
			i++;
		}			
	}
	return (s);
}
