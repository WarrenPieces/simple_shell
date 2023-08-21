#include "main.h"

void execmd(char **argv)
{
	char *com = NULL;
	char *true_com = NULL;

	if (argv)
	{
		com = argv[0];

		true_com = get_path(com);
		
		if (execve(true_com, argv, NULL) == -1)
		{
			perror("ERROR...");
		}
	}
}
