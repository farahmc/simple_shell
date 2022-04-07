#include "shell.h"

/**
 *
 *
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

	printf("test print of linked list:\n");
	print_pathlist(*head);

	return (0);
}

/**
 *
 *
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
 *
 *
 *
 */
size_t print_pathlist(list_path *head)
{
	if (head == NULL)
		return (0);

	while (head != NULL)
	{
		printf("Path is: %s\n", head->pathtoken);
		head = head->next;
	}
	return (0);
}

/**
 *
 *
 *
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
