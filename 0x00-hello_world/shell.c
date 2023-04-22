#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_ARGS 64
#define MAX_CMD_LEN 1024

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void execute(char *argv[], char *infile, char *outfile) {
    pid_t pid;
    int status;
    int in_fd, out_fd;

    pid = fork();
    if (pid == -1) {
        error("Fork failed");
    } else if (pid == 0) {
        if (infile) {
            in_fd = open(infile, O_RDONLY);
            if (in_fd == -1) {
                error("Input file open failed");
            }
            if (dup2(in_fd, STDIN_FILENO) == -1) {
                error("Input redirect failed");
            }
            close(in_fd);
        }
        if (outfile) {
            out_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (out_fd == -1) {
                error("Output file open failed");
            }
            if (dup2(out_fd, STDOUT_FILENO) == -1) {
                error("Output redirect failed");
            }
            close(out_fd);
        }
        execvp(argv[0], argv);
        error("Execution failed");
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Command failed with exit status %d\n", WEXITSTATUS(status));
        }
    }
}

void execute_pipe(char *argv[], char *prev_token, int fds[], char *infile, char *outfile) {
    pid_t pid;
    int status;
    int in_fd, out_fd;

    pid = fork();
    if (pid == -1) {
        error("Fork failed");
    } else if (pid == 0) {
        if (prev_token) {
            if (dup2(fds[0], STDIN_FILENO) == -1) {
                error("Input redirect failed");
            }
            close(fds[0]);
        }
        if (infile) {
            in_fd = open(infile, O_RDONLY);
            if (in_fd == -1) {
                error("Input file open failed");
            }
            if (dup2(in_fd, STDIN_FILENO) == -1) {
                error("Input redirect failed");
            }
            close(in_fd);
        }
        if (outfile) {
            out_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (out_fd == -1) {
                error("Output file open failed");
            }
            if (dup2(out_fd, STDOUT_FILENO) == -1) {
                error("Output redirect failed");
            }
            close(out_fd);
        }
        if (prev_token) {
            close(fds[1]);
        }
        execvp(argv[0], argv);
        error("Execution failed");
    } else {
        if (prev_token) {
            close(fds[0]);
        }
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Command failed with exit status %d\n", WEXITSTATUS(status));
        }
    }
}

void parse(char *cmdline, char *argv[], char **infile, char **outfile) {
    int argc = 0;
    int redirect_in = 0;
    int redirect_out = 0;
    char *token = strtok(cmdline, " \t\n");
    while (token != NULL) {
        if (strcmp(token, "<") == 0) {
            redirect_in = 1;
            token = strtok(NULL, " \t\n");
            *infile = token;
        } else if (strcmp(token, ">") == 0) {
            redirect_out = 1;
            token = strtok(NULL, " \t\n");
            *outfile = token;
        } else {
            argv[argc++] = token;
        }
        token = strtok(NULL, " \t\n");
    }
    argv[argc] = NULL;
    if (redirect_in || redirect_out) {
        argv[argc - redirect_in - redirect_out] = NULL;
    }
}

int main(void) {
    char cmdline[MAX_CMD_LEN];
    char *args[MAX_ARGS];
    char *infile = NULL;
    char *outfile = NULL;
    char *token, *prev_token;
    struct stat sb;

    while (1) {
        printf("$ ");
        if (fgets(cmdline, MAX_CMD_LEN, stdin) == NULL) {
            break;
        }
        cmdline[strlen(cmdline) - 1] = '\0';

        /* Parse commands separated by pipes */
        token = strtok(cmdline, "|");
        prev_token = NULL;
        while (token != NULL) {
            parse(token, args, &infile, &outfile);
            if (args[0] == NULL) {
                break;
            }
            if (strcmp(args[0], "exit") == 0) {
                break;
            }
            if (stat(args[0], &sb) == -1) {
                fprintf(stderr, "%s: command not found\n", args[0]);
                break;
            }
            if (prev_token) {
                int fds[2];
                if (pipe(fds) == -1) {
                    error("Pipe failed");
                }
                execute_pipe(args, prev_token, fds, infile, outfile);
                close(fds[1]);
                infile = NULL;
                outfile = NULL;
                args[0] = NULL;
                prev_token = NULL;
            } else {
                execute(args, infile, outfile);
                infile = NULL;
                outfile = NULL;
                args[0] = NULL;
                prev_token = token;
            }
            token = strtok(NULL, "|");
        }

        /* Wait for all child processes to complete */
        while (wait(NULL) != -1);

        /* Reset redirections */
        infile = NULL;
        outfile = NULL;
    }

    return 0;
}

