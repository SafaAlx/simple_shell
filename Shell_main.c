#include "shell.h"
#include <signal.h>

/**
 * main - Entry point
 *
 * Description: 'Launch the shell'
 * @argc: argument counter
 * @argv: arguments
 * @env: environment var
 *
 * Return: 1.
 */
int main(int argc, char **argv, char **env)
{
	char *line;
	int _isatty;
	int statusbuffer = 0;
	int status_pid = 0;
	char *_ARGS_PATH[] = {"/bin/", "/sbin/",
		"/usr/local/sbin/", "/usr/local/bin/",
		"/usr/sbin/", "/usr/bin/", "/snap/bin/", NULL};
	signal(SIGINT, int_handler);
	prompt_func();
	_isatty = isatty(0);
	while (1)
	{
		if (argc == 1)
		{
			line = malloc(sizeof(char) * SIZEBUFFER + 1);
			if (!line)
				exit(100);
			line[SIZEBUFFER] = '\0';
			statusbuffer = listen_read(line);
			if (statusbuffer == -1)
			{
				free(line);
				exit(status_pid);
			}
		}
		status_pid = string_split(argc, argv, line, _ARGS_PATH, env);
		if (_isatty != 0)
			prompt_func();
		fflush(stdin);
		fflush(stdout);
		if (_isatty == 0)
			exit(status_pid);
	}
	return (status_pid);
}

/**
 * prompt_func - function for the print symbol befor the user types
 *
 * Return: nothing.
 */
void prompt_func(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 13);
}
