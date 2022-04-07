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
	list_path *ptr, *head = NULL;
	int commandlen, pathlen;
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

	if (break_up_path (path, &head) == 1)
		return (NULL);

	commandlen = _strlen(command);
	ptr = head;

	while (ptr != NULL)
	{
		pathlen = _strlen(ptr->pathtoken);
		pathname = malloc(sizeof(char) * (commandlen + pathlen + 2));

		if (pathname == NULL)
		{
			free_pathlist(head);
			return (NULL);
		}
		_strcpy(pathname, ptr->pathtoken);
		_strcat(pathname, "/");
		_strcat(pathname, command);

		if (access(pathname, F_OK | X_OK) == 0)
		{
			free_pathlist(head);
			return (pathname);
		}
		else
		{
			free(pathname);
		}

		ptr = ptr->next;
	}

	free_pathlist(head);
	return (NULL);
}
