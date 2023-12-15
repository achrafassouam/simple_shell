#include "shell.h"

/**
 * run_inpt - run the code using execve
 * @inpt: command
 * @av: array of string
 * @id: index
 *
 * Return: exit status
 */

int run_inpt(char **inpt, char **av, int id)
{
	char *entire_command;
	pid_t pid;
	int stats;

	entire_command = _gpath(inpt[0]);
	if (entire_command == NULL)
	{
		_perror(av[0], inpt[0], id);
		free_adv(inpt);
		return (127);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(entire_command, inpt, environ) == -1)
		{
			free_null(entire_command);
			free_adv(inpt);
		}
	}
	else
	{
		waitpid(pid, &stats, 0);
		free_adv(inpt);
		free_null(entire_command);
	}

	return (WEXITSTATUS(stats));
}
