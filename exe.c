#include "main.h"

void execmd(char **argv, char envrn)
{
	char *com = NULL;
	char *true_com = NULL;
	int i1 = 0;

	if (argv && argv[0])
	{
		com = argv[0];

		if (strcmp(com, "exit") == 0)
		{
			for (i1 = 0; argv[i1] != NULL; i1++)
			{
				free(argv[i1]);
			}
			free(argv);
			exit(0);
		}
		else if (strcmp(com, "env") == 0)
		{
			while (envrn)
			{
				printf("%d\n", envrn);
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
				printf("Command not found... %s\n", com);
			}

			free(true_com);
			 for (i1 = 0; argv[i1] != NULL; i1++)
			 {
				free(argv[i1]);
			 }
			free(argv);
		}
	}
}
