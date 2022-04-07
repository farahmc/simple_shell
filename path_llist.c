#include "shell.h"

/**
 * add_node_pathlist - adds a new node to a path_list linked list
 * @head: pointer to the start of the list
 * @token: string to be included
 * Return: 0 for success, 1 for malloc fail
 */
int add_node_pathlist(list_path **head, char *token)
{
	list_path *new, *hold;

	if (head == NULL || token == NULL)
		return (1);

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		while (*head != NULL)
		{
			free(token);
			hold = (*head)->next;
			free((*head)->pathtoken);
			free(*head);
			*head = hold;
		}
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

	token = strtok(envpath, "=");
	token = strtok(NULL, ":");

	while (token != NULL)
	{
		if (add_node_pathlist(head, _strdup(token)) == 1)
			return (1);
		token = strtok(NULL, ":");
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
	list_path *release, *hold;

	if (head == NULL)
		return;

	release = head;
	hold = head;

	while (hold != NULL)
	{
		hold = release->next;
		free(release->pathtoken);
		free(release);
		release = hold;
	}
}
