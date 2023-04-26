#include "shell.h"
/**
 * parse_line - Tokenizes a string into an array of strings.
 * @line: string to tokenize.
 * Return: A pointer to an array of strings if successful, NULL if not.
 */
char **parse_line(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	size_t i = 0, token_count = 0;

	/* Count number of tokens in the line */
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\n')
			token_count++;
		i++;
	}
	/* Allocate memory for array of tokens */
	tokens = malloc(sizeof(char *) * (token_count + 1));
	if (!tokens)
	{
		perror("malloc");
		return (NULL);
	}
	/* Tokenize the line */
	i = 0;
	token = strtok(line, " \n");
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
