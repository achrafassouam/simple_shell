#include "shell.h"

/**
 * builtins_checker - checks if there is a builtin
 * @inpt: command
 *
 * Return: 1 if found, 0 if not
 */

int builtins_checker(char *inpt)
{
	char *builtins[] = {"exit", "env", NULL};
	int i;

	i = 0;

	while (builtins[i])
	{
		if (_strcmp(inpt, builtins[i]) == 0)
			return (1);
		i++;
	}

	return (0);
}

/**
 * builtin_execute - execute builtin
 * @inpt: command
 * @av: arguments
 * @stats: exit statuts
 * @id: index
 */

void builtin_execute(char **inpt, char **av, int *stats, int id)
{
	(void) av;
	(void) id;

	if (_strcmp(inpt[0], "exit") == 0)
		exit_builtin(inpt, stats);

	else if (_strcmp(inpt[0], "env") == 0)
		env_builtin(inpt, stats);
}

/**
 * exit_builtin - exit the shell
 * @inpt: command
 * @stats: exit status
 *
 */

void exit_builtin(char **inpt, int *stats)
{
	free_adv(inpt);
	exit(*stats);
}

/**
 * env_builtin - print env
 * @inpt: command
 * @stats: status
 *
 */

void env_builtin(char **inpt, int *stats)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}

	free_adv(inpt);
	*stats = 0;
}

