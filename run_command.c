#include "shell.h"

/**
 * run_inpt - run the code using execve
 * @inpt: command
 * @av: array of string
 *
 * Return: exit status
 */

int run_inpt(char **inpt, char **av)
{
	pid_t pid;
	int stats;
	(void)av;

	pid = fork();
	if (pid == 0)
	{
		if (execve(inpt[0], inpt, environ) == -1)
			free_adv(inpt);

	}
	else
	{
		waitpid(pid, &stats, 0);
		free_adv(inpt);
	}
	return (WEXITSTATUS(stats));
}
