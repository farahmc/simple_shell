#include <stdlib.h>

/**
 * _strlen - counts the chars in a string up to the null byte
 * @str: the string to be traversed
 *
 * Return: the string length (number of chars)
 */
int _strlen(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	str++;

	return (1 + _strlen(str));
}
