#include "main.h"

void execmd(char **argv, char **envp)
{
    char *com = NULL;
    char *true_com = NULL;

    if (argv && argv[0])
    {
        com = argv[0];

        if (strcmp(com, "exit") == 0)
        {
            free(argv);
            exit(0);
        }
        else if (strcmp(com, "env") == 0)
        {
            while (*envp)
            {
                printf("%s\n", *envp);
                envp++;
            }
        }
        else
        {
            true_com = get_path(com);

            if (true_com)
            {
                if (execve(true_com, argv, envp) == -1)
                {
                    perror("ERROR...");
                }
            }
            else
            {
                fprintf(stderr, "Command not found... %s\n", com);
            }

            free(true_com);
        }
        free(argv);
    }
}
