#include "main.h"

/**
 * main - main function
 *
 * Return: always 0
 */

int main(int ac, char **argv)
{
	char *prompt = "(CCS) $ ";
	char *line = NULL, *line_c = NULL;
	size_t b = 0;
	ssize_t char_read;
	char *line_c = NULL;
	const char *dlim = "\n";
	int tkn_num = 0;
	char *tkn;
	int i1;

	void(ac);

	while (1)
        {
                printf("%s", prompt);
                char_read = getline(&line, &b, stdin);

                if (char_read == -1)
                {
                        printf("Ending Shell...\n");
                        return (-1);
                }

		line_c = malloc(sizeof(char) * char_read);

		if (line_c == NULL)
		{
			perror("Memory allocation error");
			return (-1);
		}

		strcpy(line_c, line);
	
		tkn = strtok(line, dlim);

		while (tkn != NULL)
		{
			tkn_num++;
			tkn =strtok(NULL, dlim);
		}

		tkn_num++;

		argv = malloc(sizeof(char *) * tkn_num);

		tkn = strtok(line_c, dlim);

		for (i1 = 0; tkn != NULL; i1++)
		{
			argv[i1] = malloc(sizeof(char) * strlen(tkn));
			strcpy(argv[i1], tkn);

			tkn = strtok(NULL, dlim);
		}

		argv[i1] = NULL;

		execmd(argv);
	}

	free(line);
	free(line_c);

	return (0);
}
