#include "shell.h"

/**
 * _strlen - counts number of characters in string
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

/**
 * _strcat - appends one string at the end of another
 * @dest: pointer to the string to be modified
 * @src: pointer to the string to be added
 * Return: returns  pointer dest (modified string)
 */
char *_strcat(char *dest, char *src)
{
	int destlen, idx;

	if (dest == NULL)
		return (NULL);

	if (src == NULL || *src == '\0')
		return (dest);

	destlen = _strlen(dest);

	idx = 0;
	while (src[idx] != '\0')
	{
		dest[destlen + idx] = src[idx];
		idx++;
	}

	dest[destlen + idx] = '\0';

	return (dest);
}

/**
 * _strcpy - copies string at src into memory at dest
 * @dest: pointer to the space for string
 * @src: pointer to string to be copied
 * Return: nothing
 */
void _strcpy(char *dest, char *src)
{
	int i;

	if (src == NULL || *src == '\0')
		return;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

/**
 * _strcmp - compare 2 strings
 * @s1: first string
 * @s2: second string to compare
 *
 * Description: compare each value between 2 strings
 * if the value is the same, return a 0
 * if the value is larger, return a positive number
 * if the value is smaller, return a negative number
 *
 * Return: the difference in value
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;

	return (s1[i] - s2[i]);
}

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
