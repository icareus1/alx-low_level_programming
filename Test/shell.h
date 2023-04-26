#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

#define MAX_LINE 80
#define MAX_ARGS 10

char **parse_line(char *line);
int run_command(char **args, char **env);
int is_built_in(char *command);
int sh_cd(char **args);
int sh_exit(char **args);
int sh_env(char **env);
void handle_signal(int sig_num);
int main(int argc, char *argv[], char **env);

#endif
