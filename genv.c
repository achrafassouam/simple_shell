#include "shell.h"

/**
 * _genv - get environment function
 * @variable: char type var
 *
 * Return: NULL
 */

char *_genv(char *variable)
{
	char *buffer, *key, *token, *environment;
	int i;

	for (i = 0; environ[i]; i++)
	{
		buffer = _strdup(environ[i]);
		key = strtok(buffer, "=");

		if (_strcmp(key, variable) == 0)
		{
			token = strtok(NULL, "\n");
			environment = _strdup(token);
			free(buffer);
			return (environment);
		}

		free_null(buffer);
	}
	return (NULL);
}
