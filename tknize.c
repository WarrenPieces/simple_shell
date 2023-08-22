#include "main.h"

/**
 * tokenize_input - Tokenizes the input line.
 * @line: Line to tokenize.
 * @dlim: Delimiter.
 * Return: A pointer to an array of tokenized arguments.
 */

char **tokenize_input(char *line, const char *dlim)
{
	char *line_c, *tkn;
	int tkn_num, i;
	char **cmd_argv;

	line_c = strdup(line);
	tkn_num = 0;
	tkn = strtok(line_c, dlim);

	while (tkn)
	{
		tkn_num++;
		tkn = strtok(NULL, dlim);
	}
	free(line_c);

	cmd_argv = malloc(sizeof(char *) * (tkn_num + 1));
	tkn = strtok(line, dlim);
	for (i = 0; tkn; i++)
	{
		cmd_argv[i] = strdup(tkn);
		tkn = strtok(NULL, dlim);
	}
	cmd_argv[i] = NULL;

	return (cmd_argv);
}
