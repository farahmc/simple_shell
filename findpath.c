#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

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
	char *pathname, *path;

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
