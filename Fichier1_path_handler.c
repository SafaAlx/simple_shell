#include "shell.h"

/*Function 01: *get_path*/
/*Function 02: **path_params*/
/*Function 03: *getline*/

/**
 * *get_path - gets the path
 *@envp: environment variable pointer
 * Return: space
 */
char *get_path(char **envp)
{
	char *tmp;

	while (*envp != NULL)
	{
		tmp = strtok(*envp, "=");
		if (stringcmp(tmp, "PATH") == 0)
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
	while (p != NULL)
	{
		i++;
		p = strtok(NULL, ":");
		parameters[i] = p;
	}
	return (parameters);
}
