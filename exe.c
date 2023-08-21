#include "main.h"

void execmd(char **argv)
{
	char *com = NULL;

	if (argv)
	{
		com = argv[0];
		
		if (execve(com, argv, NULL) == -1)
		{
			perror("ERROR...");
		}
	}
}
