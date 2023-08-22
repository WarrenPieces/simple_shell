#include "main.h"

void execmd(char **argv, char **envp)
{
	pid_t pid;
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

	pid = fork();
	if (pid == 0)
	{
		execve(path, argv, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}
			while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(path);
}
