#include "main.h"

/**
 * process_input - process input
 *
 * @line: input
 *
 * @dlim: delimiter
 *
 * @envp: environment var
 *
 * Return: 1 if exit command, else 0
 */

int process_input(char *line, const char *dlim, char **envp)
{
	char **cmd_argv;
	char *trimmed_line = strtrim(line);

	if (line == NULL)
	{
		return (0);
	}

	if (trimmed_line == NULL)
	{
		return (0);
	}

	cmd_argv = tokenize_input(line, dlim);

	if (cmd_argv[0] && strcmp(cmd_argv[0], "exit") == 0)
	{
		free_cmd_argv(cmd_argv);
		free(trimmed_line);
		return (1);
	}
	execmd(cmd_argv, envp);
	free_cmd_argv(cmd_argv);
	free(trimmed_line);

	return (0);
}
