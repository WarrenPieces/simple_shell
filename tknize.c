#include "main.h"

/**
 * tokenize_input - tokenize input
 *
 * @line: input
 * @dlim: delimiter
 *
 * Return: array of tokens
 */

char **tokenize_input(const char *line, const char *dlim)
{
	char *line_copy = strdup(line);

	if (!line_copy)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	char **tokens = NULL;
	int token_count = 0;
	char *token = strtok(line_copy, dlim);

	while (token)
	{
		token_count++;
		tokens = realloc(tokens, sizeof(char *) * token_count);
		if (!tokens)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		tokens[token_count - 1] = strdup(token);
		if (!tokens[token_count - 1])
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, dlim);
	}

	tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
	if (!tokens)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	tokens[token_count] = NULL;
	free(line_copy);
	return (tokens);
}
