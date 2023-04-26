#include "shell.h"
/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE if not.
 */
int main(int argc, char *argv[], char **env)
{
	char *line = NULL, **args = NULL;
	size_t len = 0;
	ssize_t nread;
	(void)argc;
	(void)argv;

	signal(SIGINT, handle_signal);
	while (1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}
		args = parse_line(line);
		if (!args)
			continue;
		if (run_command(args, env) == 0)
			break;
		free(args);
		args = NULL;
	}
	free(line);
	line = NULL;
	return (EXIT_SUCCESS);
}
