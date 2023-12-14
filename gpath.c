#include "shell.h"

/**
 * _gpath - path to a command
 * @command: the command
 *
 * Return: NULL
 */

char *_gpath(char *command)
{
	char *entire_path, *inpt, *dir;
	int i;
	struct stat st;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}
	entire_path = _genv("PATH");
	if (!entire_path)
		return (NULL);

	dir = strtok(entire_path, ":");
	while (dir)
	{
		inpt = malloc(_strlen(dir) + _strlen(command) + 2);
		if (inpt)
		{
			_strcpy(inpt, dir);
			_strcat(inpt, "/");
			_strcat(inpt, command);

			if (stat(inpt, &st) == 0)
			{
				free(entire_path);
				return (inpt);
			}
			free_null(inpt);
			dir = strtok(NULL, ":");
		}
	}
	free(entire_path);
	return (NULL);
}
