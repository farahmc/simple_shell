#include <stdio.h>

/**
 * _strlen- counts number of characters in string
 * @s: string to be counted
 *
 * Description: loop to count number of characters in string
 * that is lcated by a pointer
 *
 * Return: number of characters in string
 */

int _strlen(char *s)
{
	int i;

	if (s == NULL || *s == '\0')
		return (0);

	for (i = 0; *s != '\0'; s++)
		i++;

	return (i);
}
