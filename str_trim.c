#include "main.h"

char *strtrim(char *str)
{
	char *strt = str;
	char *end = str + strlen(str) - 1;

	if (str == NULL)
	{
		printf("strtrim: received NULL pointer\n");
		return (NULL);
	}

	while (isspace((unsigned char)*strt))
	{
		strt++;
	}

	if (*strt == '\0')
	{
		char *rslt = malloc(1);
		if (rslt == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		rslt[0] = '\0';
		return rslt;
	}

	while (end > strt && isspace((unsigned char)*end))
	{
		end--;
	}

	end[1] = '\0';

	if (strt != str)
	{
		memmove(str, strt, (end - strt + 2) * sizeof(char));
	}

	return (str);
}
