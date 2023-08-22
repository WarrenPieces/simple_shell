#include "main.h"

/**
 * main - main function
 *
 * Return: always 0
 */

int main(int ac, char **argv, char **envp)
{
    char *prompt = "(CCS) $ ";
    char *line = NULL;
    size_t b = 0;
    ssize_t char_read;
    char *line_c;
    const char *dlim = " \t\r\n";
    int tkn_num;
    char *tkn;
    int i1;
    char **cmd_argv;

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

        line_c = strdup(line); 

        tkn_num = 0;
        tkn = strtok(line_c, dlim);

        while (tkn != NULL)
        {
            tkn_num++;
            tkn = strtok(NULL, dlim);
        }

        free(line_c);

        tkn_num++;

        cmd_argv = malloc(sizeof(char *) * tkn_num);
        tkn = strtok(line, dlim);

        for (i1 = 0; tkn != NULL; i1++)
        {
            cmd_argv[i1] = strdup(tkn);
            tkn = strtok(NULL, dlim);
        }

        cmd_argv[i1] = NULL;

        if (cmd_argv[0] != NULL && strcmp(cmd_argv[0], "exit") == 0)
        {
            free(line);
            free(cmd_argv);
            return 0;
        }

        execmd(cmd_argv, envp);

        for (i1 = 0; cmd_argv[i1]; i1++)
        {
            free(cmd_argv[i1]);
        }
        free(cmd_argv);
    }

    free(line);

    return (0);
}
