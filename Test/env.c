#include "shell.h"
/**
 * sh_env - Prints all the environment variables.
 * @env: An array of strings containing the environment variables.
 *
 * Return: 1 if successful.
 */
int sh_env(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
		printf("%s\n", env[i]);

	return (1);
}
