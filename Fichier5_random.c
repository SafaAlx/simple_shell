#include "shell.h"
#include <signal.h>

/**
 * int_handler - signal handler
 * @i: variable integer
 */
void int_handler(int i __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n", 1);
	fflush(stdout);
}

/**
 * listen_read - get char the client terminal & call fn until char is '\n'
 * @buffer: pointer
 * Return: 1 is successful, -1 if error.
 */
int listen_read(char *buffer)
{
	size_t bufsize = SIZEBUFFER;
	ssize_t c;

	c = get_line(&buffer, &bufsize, stdin);
	if (c == EOF)
		return (-1);
	else if (stringcmp(buffer, "exit") == 10)
		return (-1);
	return (0);
}

/**
 * chd_launch - make a fork to create child process who execute the command
 * @args: arguments
 * @_path: path
 * @_argv: argument container
 * Return: exit status
 */
int chd_launch(char **_argv, char *args, char **_path)
{
	pid_t pid;
	char *envp[] = {"", NULL}, *dir = NULL, *file = NULL, *fullpath = NULL;
	int status, j = 0, searchpath = 1, accessfile = 0;
	struct stat fileStat;

	pid = fork();
	if (pid == 0)
	{file = _argv[0];
		while (*(_path + j) != NULL && searchpath == 1)
		{searchpath = append(file);
			dir = stringconcat(NULL, *(_path + j));
			fullpath = searchpath == 1 ? stringconcat(dir, file) : file;
			if (stat(fullpath, &fileStat) == 0)
			{accessfile = 1;
				searchpath = 0; }
			j++;
			free(dir); }
		if (accessfile)
		{
			if (execve(fullpath, _argv, envp) == -1)
			{errors();
				free(args);
				free(_argv);
				exit(-1); } }
		else
		{free(args);
			free(_argv);
			errors();
			exit(2); }
	}
	else if (pid < 0)
	{free(args);
		free(_path);
		free(_argv);
		exit(102); }
	else
		waitpid(pid, &status, 0);
	return (WEXITSTATUS(status) & 255);
}
