#include "shell.h"

/*Function  01: string_split*/
/*Function 02: *stringconcat*/

/**
 * string_split - this function splits the string when space character is found
 *@argc: argument counter
 *@argv: where the arguments are contained
 *@args: arguments
 *@_path: path
 *@evp: pointer that contain environment variables
 * Return: status of execution
 */
int string_split(int argc, char **argv, char *args, char **_path, char **evp)
{
	char delimeter[] = " \n";
	char **options;
	char *argx;
	int j = 0;
	int args_max = 255, status_pid = 0;
	(void)_path;

	if (argc == 1)
	{
		if ((int)args[0] == 10)
			free(args);
		else
		{
			options = malloc(sizeof(char *) * args_max);
			if (options == NULL)
			{
				free(options);
				exit(111);
			}
			argx = strtok(args, delimeter);
			while (argx != NULL)
			{options[j] = argx;
				argx = strtok(NULL, delimeter);
				j++; }
			options[j] = NULL;
			if (stricmp(options[0], "env") == 0 && options[1] == NULL)
				printenv(ev);
			else if (options[0] != NULL && stringlen(options[0]) > 0)
				status_pid =  chd_launch(options, args, _path);
			free(args);
			free(options);
		}
	}
	else if (argc >= 2)
	{
		args_pop(argv);
		status_pid =  chd_launch(argv, NULL, _path);
	}
	return (status_pid);
}

/**
 *stringconcat - Duplicates strings
 *@str1: string one
 *@str2: string two
 * Return: pointer to copy an array
 */
char *stringconcat(char *str1, char *str2)
{
	char *parr;
	unsigned int i;
	unsigned int size_str1, size_str2;

	if (str1 == NULL)
		str1 = "";
	if (str2 == NULL)
		str2 = "";
	for (size_str1 = 0; *(str1 + size_str1) && str1; size_str1++)
	{
	}
	for (size_str2 = 0; *(str2 + size_str2) && str2; size_str2++)
	{
	}
	parr =  malloc(sizeof(char) * (size_str1 + size_str2 + 1));
	if (parr == NULL)
		return (NULL);
	for (i = 0; i < size_str1 + size_str2; i++)
	{
		if (i < size_str1)
			parr[i] = *(str1 + i);
		else
			parr[i] = *(str2 + i - size_str1);
	}
	parr[i] = '\0';
	return (parr);
}
