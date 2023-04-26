#include "shell.h"
/**
 * sh_cd - Changes the current working directory.
 * @args: command arguments.
 * Return: 1 if successful, 0 if not.
 */
int sh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: cd: expected argument to \"cd\"\n");
		return (0);
	}
	else if (chdir(args[1]) != 0)
	{
		perror("hsh");
		return (0);
	}
	return (1);
}
