#include "shell.h"

/**
 * _strdup - copy of the string in a newly allocated space in memory
 * @str: char type pointer
 * Return: pointer to the string
 */

char *_strdup(char *str)
{
	char *new;
	int i, len;

	if (str == 0)
		return (NULL);

	i = len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	new = (char *)malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	while (*str)
	{
		new[i++] = *str++;
	}
	new[i] = '\0';
	return (new);
}
