#include "shell.h"
/**
 * run_command - Executes command along with the given arguments.
 * @args: An array of strings containing the command and its arguments.
 * @env: An array of strings containing the environment variables.
 * Return: 1 if successful, or 0 if not.
 */
int run_command(char **args, char **env)
{
	pid_t pid;
	int status, valid_executable = 0;
	struct stat st;

	if (is_built_in(args[0]))
	{
		if (strcmp(args[0], "cd") == 0)
			return (sh_cd(args));
		else if (strcmp(args[0], "exit") == 0)
			return (sh_exit(args));
		else if (strcmp(args[0], "env") == 0)
			return (sh_env(env));
	}
	else
	{
		if (stat(args[0], &st) == 0 && (st.st_mode & S_IXUSR))
			valid_executable = 1;
		if (valid_executable)
		{
			pid = fork();
			if (pid == -1)
			{
				perror(args[0]);
				return (0);
			}
			else if (pid == 0)
			{
				if (execvp(args[0], args) == -1)
				{
					fprintf(stderr, "%s: %d: %s: not found\n", args[0], __LINE__, args[0]);
					return (1);
				}
			}
			else
			{
				do {
					waitpid(pid, &status, WUNTRACED);
				} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			}
		}
		else
		{
			fprintf(stderr, "%s: %d: %s: not found\n", args[0], __LINE__, args[0]);
			return (1);
		}
	}
	return (1);
}
