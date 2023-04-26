#include "shell.h"
/**
 * run_command - Executes command along with the given arguments.
 * @args: An array of strings containing the command and its arguments.
 * @env: An array of strings containing the environment variables.
 * Return: 1 if successful, or 0 if not.
 */
int run_command(char **args, char **env)
{
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
        if (check_executable(args[0]))
        {
            if (execute_command(args) == 0)
            {
                perror(args[0]);
                return (0);
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
