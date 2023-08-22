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

	if (!argv || !argv[0])
	return;

	path = get_path(argv[0]);

	if (path == NULL)
	{
		fprintf(stderr, "Command not found: %s\n", argv[0]);
		return;
	}

	pid1 = fork();
	if (pid1 == 0)
	{
		execve(path, argv, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid1 < 0)
	{
		perror("fork");
	}
	else
	{

	do	{
		waitpid(pid, &status, WUNTRACED);
	}
			while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(path);
}
