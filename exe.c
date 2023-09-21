#include "main.h"

/**
 * execmd - exe command
 *
 * @argv: arg val
 *
 * @envp: environment var
 *
 * Return: always 0
 */

void execmd(char **argv, char **envp)
{
	pid_t pid1;
	int status;
	char *path;
	char *clean_command = strtrim(argv[0]);

	if (!argv || !argv[0] || !argv[0][0])
	{
		return;
	}

	path = get_path(clean_command);

	if (path == NULL)
	{
		fprintf(stderr, "Command not found: %s\n", argv[0]);
		free(clean_command);
		return;
	}

	pid1 = fork();
	if (pid1 == 0)
	{
		if (execve(path, argv, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid1 < 0)
	{
		perror("fork");
	}
	else
	{
		do
		{
			waitpid(pid1, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(path);
	free(clean_command);
}
