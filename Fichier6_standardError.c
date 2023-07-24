#include "shell.h"

/**
 * next_args - takes the next value of argument
 * @p: pointer
 * Return: 0 on success, -1 on error
 */
int next_args(char **p)
{
	int index = 0;

	while (p[index] != NULL)
	{
		p[index] = p[index + 1];
		index++;
	}
	return (0);
}

/**
 * errors - allows the error message to be printed in shell
 *
 */
void errors(void)
{
	write(STDOUT_FILENO, __FILE__, stringlen(__FILE__));
	write(STDOUT_FILENO, "/: No such file or directory",
			stringlen("/: No such file or directory"));
	write(STDOUT_FILENO, "\n", stringlen("\n"));
}
