#include "main.h"

/**
 * get_path - gets path
 *
 * @com: command
 *
 * Return: always 0
 */

char *get_path(char *com)
{
	char *path_m;
	char *path_c;
	int com_len;
	char *p_token;
	int d_len;
	char *f_path;
	struct stat buff;

	path_m = getenv("PATH");
	
	if (strchr(com, '/') != NULL)
	{
		if (stat(com, &buff) == 0)
		{
			return strdup(com);
		}
		return NULL;
	}

	if (!path_m || path_m[0] == '\0')
	{
		return (NULL);
	}

	path_c = strdup(path_m);
	com_len = strlen(com);
	p_token = strtok(path_c, ":");

	while (p_token != NULL)
	{
		d_len = strlen(p_token);
		f_path = malloc(d_len + com_len + 2);

		strcpy(f_path, p_token);
		strcat(f_path, "/");
		strcat(f_path, com);

		if (stat(f_path, &buff) == 0)
		{
			free(path_c);
			return (f_path);
		}

		free(f_path);
		p_token = strtok(NULL, ":");
	}

	free(path_c);
	return (NULL);
}
