#include "shell.h"

/**
 * free_adv - advanced free
 * @s: double pointed char
 */

void free_adv(char **s)
{
	int i;

	if (s == NULL)
		return;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}

	free(s);
	s = NULL;
}

/**
 * free_null - free a string
 * @str: string
 */

void free_null(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}
