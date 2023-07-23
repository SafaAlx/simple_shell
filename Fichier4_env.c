#include "shell.h"

/*Function 01: *get_env_value*/
/*Function 02: env_print*/
/*Function 03: append*/

/**
 *get_env_value - finds the value of environment variable
 *@envp: environment variables
 *@var: variable to search
 *Return: pointer start on value of variable
 */
char *get_env_value(char **envp, char *var)
{
	unsigned int envp_i = 0, variable_i = 0;
	char flag;

	while (envp[envp_i])
	{
		flag = 1;
		while (var[variable_i] && flag)
		{
			if (envp[envp_i][variable_i] != var[variable_i])
				flag = 0;
			variable_i++;
		}
		if (flag)
		{
			return (&envp[envp_i][variable_i + 1]);
		}
		variable_i = 0;
		envp_i++;
	}
	return (NULL);
}

/**
* env_print - prints environment
* @env: pointer contains the list variable
* Return: 0
*/
int env_print(char **env)
{
	int m = 0;

	while (*(env + m) != NULL)
	{
		write(STDOUT_FILENO, *(env + m), stringlen(*(env + m)));
		write(STDOUT_FILENO, "\n", stringlen("\n"));
		m++;
	}
	return (0);
}

/**
 * append - appends the "." and "/" of the commands in environment path
 *@cmd: command
 * Return: 0 or 1
 */
int append(char *cmd)
{
	int j = 0;

	while (cmd[j] != '\0')
		j++;
	if (j > 2)
	{
		if (cmd[0] == '.' || cmd[0] == '/')
			return (0);
	}
	return (1);
}
