#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

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
 * file_path - breaks $PATH into tokens to search for command in each dir
 * @command: a string containing the command
 *
 * Return: a string containing the correct filename and command or NULL
 */
char *file_path(char *command)
{
	int i, commandlen, pathlen;
	char *path = NULL, *token = NULL, *pathname;
	char *pathtoken[15];

	if (*command == '/')
	{
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		else
			return (NULL);
	}

	path = _getenv("PATH");
	token = strtok(path, "=");
	token = strtok(NULL, ":");

	for (i = 0; token != NULL; i++)
	{
		pathtoken[i] = token;
		token = strtok(NULL, ":");
	}
	pathtoken[i] = NULL;

	i = 0;
	commandlen = _strlen(command);

	while (pathtoken[i] != NULL)
	{
		pathlen = _strlen(pathtoken[i]);
		pathname = malloc(sizeof(char) * (commandlen + pathlen + 2));
		if (pathname == NULL)
			return (NULL);
		_strcpy(pathname, pathtoken[i]);
		_strcat(pathname, "/");
		_strcat(pathname, command);
		if (access(pathname, F_OK | X_OK) == 0)
			return (pathname);
		else
			free(pathname);
		i++;
	}

	return (NULL);
}
