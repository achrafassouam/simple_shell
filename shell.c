#include "shell.h"

/**
 * main - simple shell main function
 * @ac: argument count
 * @av: array of string
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	char *linep = NULL;
	char **inpt = NULL;
	int stats = 0;
	int id = 0;
	(void)ac;

	do {
		/* line input */
		linep = get_input();
		if (linep == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(1, "\n", 1);
			}
			return (stats);
		}
		id++;
		/* split input using strtok */
		inpt = _splitter(linep);
		if (!inpt)
			continue;
		if (builtins_checker(inpt[0]))
		{
			builtin_execute(inpt, av, &stats, id);
		}
		else
		{
			stats = run_inpt(inpt, av, id);
		}
	} while (1);
}

