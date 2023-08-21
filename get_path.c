#include "main.h"

char *get_path(char *com)
{

	char *path_m;
	char *path_c;
	int com_len;
	char *p_token;
	int d_len;
	char *f_path;
	struct stat buffer;

	path_m = getenv("PATH");

	if (path_m)
	{
		path_c = strdup(path_m);
		com_len = strlen(com);
		p_token = strtok(path_c, ":");

		while (p_token != NULL)
		{
			d_len = strlen(p_token);
			f_path = malloc(com_len + d_len + 2);

			strcpy(f_path, p_token);
        		strcpy(f_path, "/");
        		strcpy(f_path, com);
        		strcpy(f_path, "\0");

			if (stat(f_path, &buffer) == 0)
			{
				return (f_path);
			}
		}
	}
		else
		{
			p_token = strtok(NULL, ":");
		}

	if (stat(com, &buffer) == 0)
	{
		return (com);
	}
	
	free(path_c);
	free(f_path);

	return (NULL);
}
