#include "main.h"

/**
 * main - shell emulation
 *
 * @ac: arg count
 *
 * @argv: arg values
 *
 * @envp: environment var
 *
 * Return: 0 on success, -1 on failure
 */

int main(int ac, char **argv, char **envp)
{
	char *prompt = "$ ";
	char *line = NULL;
	const char *dlim = " \t\r\n";
	size_t b = 0;
	ssize_t char_read;

	(void)ac;
	(void)argv;

	while (1)
	{
		char *token = strtok(line, "|");
		printf("%s", prompt);
		char_read = getline(&line, &b, stdin);

		if (char_read == -1)
		{
			printf("Ending Shell...\n");
			free(line);
			return (-1);
		}

		while (token)
		{
			int result = process_input(token, dlim, envp);

			if (result == 1)
			{
				break;
			}
			token = strtok(NULL, "|");
		}
	}

	free(line);
	return (0);
}
