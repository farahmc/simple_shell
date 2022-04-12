#include <stdlib.h>
#include <stdio.h>

/**
 * _strtok - returns a pointer to the next token in a string, as defined by
 * by the delim string.
 * @string: the string to be parsed
 * @delim: an immutable string containing token delimiters
 * Return: a pointer to the first or next token
 */
char *_strtok(char *string, const char *delim)
{
	int i = 0;
	int j = 0;
	static char *ptr = "\0";

	if (string == NULL && *ptr == '\0')
		return (NULL);

	if (string == NULL)
		string = ptr;

	while (string[i] != '\0' && delim[j] != '\0')
	{
		if (string[i] == delim[j])
		{
			string++;
			j = 0;
		}
		else
			j++;
	}

	while (string[i] != '\0')
	{
		j = 0;
		while (delim[j] != '\0')
		{
			if (string[i] == delim[j])
			{
				string[i] = '\0';
				ptr = string + i + 1;
				return (string);
			}
			j++;
		}
		i++;
	}

	ptr = string + i;

	return (string);
}
