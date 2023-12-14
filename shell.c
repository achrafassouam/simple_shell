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
		/* run the input using execve */
		stats = run_inpt(inpt, av, ad);
	} while (1);
}

