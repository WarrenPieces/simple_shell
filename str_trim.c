#include "main.h"

char *strtrim(char *str)
{
	char *strt = str;
	char *end = str + strlen(str) - 1;

	if (str == NULL)
	{
		return (NULL);
	}

	while (isspace((unsigned char)*strt))
	{
		strt++;
	}

	if (*strt == '\0')
	{
		*str = '\0';
		return str;
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
