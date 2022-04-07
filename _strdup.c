#include "shell.h"

/**
 * _strdup - returns a pointer to a space in memory containing copy of a string
 * @str: the string to be copied
 *
 * Return: pointer to the memory allocation
 */
char *_strdup(char *str)
{
	char *newstring;
	int idx, size;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;

	newstring = malloc(sizeof(*newstring) * size);

	if (newstring == NULL)
		return (NULL);

	idx = 0;
	while (idx < size)
	{
		newstring[idx] = str[idx];
		idx++;
	}

	return (newstring);
}
