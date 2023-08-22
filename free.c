#include "main.h"

/**
 * free_cmd_argv - Frees the command arguments.
 * @cmd_argv: Command arguments to free.
 */

void free_cmd_argv(char **cmd_argv)
{
	int i1;

	for (i1 = 0; cmd_argv[i1]; i1++)
		free(cmd_argv[i1]);
	free(cmd_argv);
}
