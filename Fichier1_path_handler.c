#include "shell.h"

/*Function 01: *get_path*/
/*Function 02: **path_params*/
/*Function 03: *getline*/

/**
 * *get_path - gets the path
 *@envp: environment variable pointer
 * Return: space - " "
 */
char *get_path(char **envp)
{
	char *tmp;

	while (*envp != NULL)
	{
		tmp = strtok(*envp, "=");
		if (stricmp(tmp, "PATH") == 0)
		{
			tmp = strtok(NULL, "\0");
			return (tmp);
		}
		envp++;
	}
	return ("");
}

/**
 * **path_params - sets the path parameters
 *@path: the path of the shell
 * Return: parameters
 */
char **path_params(char *path)
{
	int i = 0;
	char *p;
	int limitparameters = 255;
	char **parameters;

	parameters = malloc(sizeof(char *) * limitparameters);
	if (parameters == NULL)
		exit(114);
	p = strtok(path, ":");
	parameters[i] = p;
	while (p)
	{
		i++;
		p = strtok(NULL, ":");
		parameters[i] = p;
	}
	return (parameters);
}

/**
 * getline - get line from the command
 * Return: buffer
 */
char *getline(void)
{
	char *buf = NULL;
	int Test;
	size_t buf_size = 0;


	Test = getline(&buf, &buf_size, stdin);
	buffers3(NULL, buf);

	if (Test == EOF)
	{
		buffers1(NULL, NULL);
		buffers2(NULL, NULL);
		buffers3(NULL, NULL);
		buffers4(NULL, NULL);
		buffers5(NULL);
		_exit(0);
	}
	return (buf);
}
