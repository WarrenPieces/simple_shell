#include "main.h"

/**
 * main - main function
 *
 * Return: always 0
 */

int main(int ac, char **argv)
{
	char *prompt = "(CCS) $";
	char *line;
	size_t b = 0;

	(void)ac; (void)argv;

	printf("%s", prompt);
	getline(&line, &b, stdin);
	printf("%s\n", line);

	free(line);
	return(0);
}
