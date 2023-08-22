#include "main.h"

/**
 * main - A shell emulation.
 * @ac: Argument count.
 * @argv: Argument values.
 * @envp: Environment variables.
 * Return: 0 on success, -1 on failure.
 */

int main(int ac, char **argv, char **envp)
{
    char *prompt = "$ ";
    char *line = NULL;
    const char *dlim = " \t\r\n";
    size_t b = 0;
    ssize_t char_read;

    (void)ac;
    (void)argv;

    while (1)
    {
        printf("%s", prompt);
        char_read = getline(&line, &b, stdin);

        if (char_read == -1)
	{
            printf("Ending Shell...\n");
            free(line);
            return (-1);
        }

        if (process_input(line, dlim, envp))
            break;
    }

    free(line);
    return (0);
}
