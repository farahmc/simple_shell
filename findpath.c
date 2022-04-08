#include "shell.h"

/**
 * path_given - checks if the string starts with a '/'
 * @command: the string to be checked
 * Return: 1 for true, 0 for false
 */
int path_given(char *command)
{
	if (*command == '/')
		return (1);

	return (0);
}

/**
 * file_path - breaks $PATH into tokens to search for command in each dir
 * @command: a string containing the command
 * @error: a string containing the error string to be returned if
 * access fails
 * Return: a string containing the correct filename and command or NULL
 */
char *findpath(char *command, char *error)
{
	list_path *ptr, *head = NULL;
	int commandlen, pathlen;
	char *pathname, *path;


	path = _getenv("PATH");
	path = _strdup(path);

	if (break_up_path(path, &head) == 1)
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
	return (error);
}

/**
 * checkpath - checks that a command can be executed at
 * at the given location
 * @pathname: string with full path and filename
 * Return: 0 for execution possible, 1 if not
 */
int checkpath(char *pathname)
{
	if (access(pathname, F_OK | X_OK) == 0)
		return (0);

	return (0);
}
