#include "main.h"

void execmd(char **argv)
{
	char *com = NULL;
	char *true_com = NULL;
	char **envrn = environ;

	if (argv)
	{
		com = argv[0];

		if (strcmp(com, "exit") == 0)
		{
			free(true_com);
			free(argv);
			exit(0);
		}
		else if (strcmp(com, "env") == 0)
		{
			while (*envrn)
			{
				printf("%s\n", *envrn);
				envrn++;
			}
		}
		else
		{
			true_com = get_path(com);

			if (true_com)
			{
				if (execve(true_com, argv, NULL) == -1)
				{
					perror("ERROR...");
				}
			}
			else
			{
				printf(stderr, "Command not found... %s\n", com);
			}

			free(true_com);
			free(argv);
		}
	}
}
