#include "shell.h"

/*Function 01: stringcmp*/
/*Function 02: stringcat*/
/*Function 03: stringlen*/

/**
 * stringcmp - Compare two strings
 * @str1: string
 * @str2: string
 * Return: if str1 < str2, 0 if matching, and positive if str1 > str2
 */
int stringcmp(char *str1, char *str2)
{
	int j;

	for (j = 0; str1[j] != '\0' || str2[j] != '\0'; j++)
	{
		if (str1[j] != str2[j])
			return (str1[j] - str2[j]);
	}
	return (0);
}

/**
 * char *stringcat - concatenates two strings.
 * @destination: string destination
 * @source: string source
 *
 * Return: Always 0
 */
char *stringcat(char *destination, char *source)
{
	int i = 0;
	int j = 0;

	while (destination[i])
	{
		i++;
	}
	while (source[j])
	{

		destination[i + j] = source[j];
		j++;
	}
	destination[i + j] = source[j];
	return (destination);
}

/**
 * stringlen - returns the length of a string.
 *@p: pointer
 * Return: length
 */
long int stringlen(char *p)
{
	long int k = 0;

	while (p[k] != '\0')
		k++;
	return (k);
}
