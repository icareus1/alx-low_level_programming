#include "shell.h"
/**
 * check_executable - Checks if a file is executable.
 * @filename: The name of the file to be checked.
 *
 * Return: 1 if the file is executable, 0 if not.
 */
int check_executable(char *filename)
{
    struct stat st;

    if (stat(filename, &st) == 0 && (st.st_mode & S_IXUSR))
        return (1);

    return (0);
}

/**
 * execute_command - Executes a command along with its arguments.
 * @args: An array of strings containing the command and its arguments.
 *
 * Return: 1 if the command was executed successfully, 0 if not.
 */
int execute_command(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        /* Failed to create a child process */
        return (0);
    }
    else if (pid == 0)
    {
        /* Child process */
        if (execvp(args[0], args) == -1)
        {
            /* Failed to execute the command */
            return (0);
        }
    }
    else
    {
        /* Parent process */
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return (1);
}

