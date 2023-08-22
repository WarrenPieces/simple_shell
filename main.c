#include "main.h"

/**
 * main - main function
 *
 * Return: always 0
 */

/**
 * main - A shell emulation.
 * @ac: Argument count.
 * @argv: Argument values.
 * @envp: Environment variables.
 * Return: 0 on success, -1 on failure.
 */

int main(int ac, char **argv, char **envp)
{
	char *prompt = "($ ";
	char *line = NULL, *line_c, *tkn;
	const char *dlim = " \t\r\n";
	int tkn_num, i;
	size_t b = 0;
	ssize_t char_read;
	char **cmd_argv;

	(void)ac;
	(void)argv;

	while (1)
	{
		printf("%s", prompt);
		char_read = getline(&line, &b, stdin);

		if (char_read == -1)
		{
			printf("Ending Shell...\n");
			free(line);
			return (-1);
		}

		line_c = strdup(line);

		tkn_num = 0;
		tkn = strtok(line_c, dlim);

		while (tkn != NULL)
		{
			tkn_num++;
			tkn = strtok(NULL, dlim);
		}

		free(line_c);

		cmd_argv = malloc(sizeof(char *) * (tkn_num + 1));
		tkn = strtok(line, dlim);

		for (i = 0; tkn != NULL; i++)
		{
			cmd_argv[i] = strdup(tkn);
			tkn = strtok(NULL, dlim);
		}

		cmd_argv[i] = NULL;

		if (cmd_argv[0] != NULL && strcmp(cmd_argv[0], "exit") == 0)
		{
			free(line);
			for (i = 0; cmd_argv[i]; i++)
			free(cmd_argv[i]);
			free(cmd_argv);
			return (0);
		}

		execmd(cmd_argv, envp);

		for (i = 0; cmd_argv[i]; i++)
		{
			free(cmd_argv[i]);
		}
		free(cmd_argv);
	}

	free(line);

	return (0);
}
