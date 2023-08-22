#include "main.h"

/**
 * process_input - Process the input line.
 * @line: Input line.
 * @dlim: Delimiter.
 * @envp: Environment variables.
 * Return: 1 if exit command, 0 otherwise.
 */

int process_input(char *line, const char *dlim, char **envp)
{
    char **cmd_argv;

    cmd_argv = tokenize_input(line, dlim);
    if (cmd_argv[0] && strcmp(cmd_argv[0], "exit") == 0)
    {
        free_cmd_argv(cmd_argv);
        return (1);
    }
    execmd(cmd_argv, envp);
    free_cmd_argv(cmd_argv);
    return (0);
}
