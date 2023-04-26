#include "shell.h"
/**
 * is_built_in - Checks if the given command is a built-in shell command.
 * @command: The command to check.
 * Return: 1 if the command is built-in, if not.
 */
int is_built_in(char *command)
{
	unsigned long int i;
	char *built_ins[] = {"exit", "env", "cd"};

	for (i = 0; i < sizeof(built_ins) / sizeof(char *); i++)
	{
		if (strcmp(command, built_ins[i]) == 0)
			return (1);
	}

	return (0);
}
