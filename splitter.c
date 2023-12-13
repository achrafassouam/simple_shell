#include "shell.h"

/**
 * _splitter - split the input into tokens
 * @linep: buffer
 *
 * Return: command
 */

char **_splitter(char *linep)
{
	char *token = NULL, *buffer = NULL;
	char **inpt = NULL;
	int i = 0, j = 0;

	if (linep == NULL)
		return (NULL);

	buffer = _strdup(linep);
	token = strtok(buffer, " \t\n");
	if (token == NULL)
	{
		free_null(linep), free_null(buffer);
		return (NULL);
	}
	while (token)
	{
		i++;
		token = strtok(NULL, " \t\n");
	}
	free_null(buffer);
	inpt = malloc(sizeof(char *) * (i + 1));
	if (inpt == NULL)
	{
		free_null(linep);
		return (NULL);
	}
	token = strtok(linep, " \t\n");
	while (token)
	{
		inpt[j] = _strdup(token);
		token = strtok(NULL, " \t\n");
		j++;
	}
	free_null(linep), inpt[i] = NULL;
	return (inpt);
}
