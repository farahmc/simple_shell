#include "shell.h"

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

	return (1);
}

/**
 * findpath - breaks $PATH into tokens to search for command in each dir
 * @command: a string containing the command
 * @error: a string containing the error string to be returned if
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
			free(path);
			free_pathlist(head);
			return (NULL);
		}
		_strcpy(pathname, ptr->pathtoken);
		_strcat(pathname, "/");
		_strcat(pathname, command);

		if (access(pathname, F_OK | X_OK) == 0)
		{
			free_pathlist(head);
			free(path);
			return (pathname);
		}
		else
		{
			free(pathname);
		}
		ptr = ptr->next;
	}
	free_pathlist(head);
	free(path);
	return (error);
}

/**
 * add_node_pathlist - adds a new node to a path_list linked list
 * @head: pointer to the start of the list
 * @token: string to be included
 * Return: 0 for success, 1 for malloc fail
 */
int add_node_pathlist(list_path **head, char *token)
{
	list_path *new;

	if (head == NULL || token == NULL)
		return (1);

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		free_pathlist(*head);
		return (1);
	}

	new->pathtoken = token;
	new->next = *head;
	*head = new;

	return (0);
}

/**
 * break_up_path - breaks PATH into tokens
 * @envpath: a string containing the PATH
 * @head: pointer to the start of a linked list
 * Return: 0 for success, 1 for malloc fail
 */
int break_up_path(char *envpath, list_path **head)
{
	char *token;

	token = _strtok(envpath, "=");
	token = _strtok(NULL, ":");

	while (token != NULL)
	{
		if (add_node_pathlist(head, token) == 1)
		{
			free(envpath);
			return (1);
		}

		token = _strtok(NULL, ":");
	}

	return (0);
}

/**
 * free_pathlist - frees a path_list linked list
 * @head: a pointer to the start of the list
 * Return: nothing
 */
void free_pathlist(list_path *head)
{
	list_path *hold = NULL;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		hold = head->next;
		free(head);
		head = hold;
	}
}
