#include "main.h"

/**
 * free_cmd_argv - Frees the command arguments.
 * @cmd_argv: Command arguments to free.
 */

void free_cmd_argv(char **cmd_argv)
{
    int i;

    for (i = 0; cmd_argv[i]; i++)
        free(cmd_argv[i]);
    free(cmd_argv);
}
