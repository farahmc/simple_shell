#include "shell.h"

/**
 *
 *
 */
int add_node_pathlist(path_list **head, char **string)
{
	list_path *new, hold;

	if (head == NULL || string == NULL)
		reutrn (1);

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		while (*head != NULL)
		{
			hold = (*head)->next;
			free((*head)->pathtoken);
			free(*head);
			*head = hold;
		}
		return (1);
	}

	new->pathtoken = *string;
	new->next = *head;
	*head = new;

	return (0);
}

/**
 *
 *
 *
 */
size_t print_pathlist(path_list *head)
{
	if (head == NULL)
		return (0);

	printf("Test print: Path is: %s\n", head->pathtoken);

	return (1 + print_list_path(head));
}

/**
 *
 *
 */
int break_up_path(char *envpath, list_path **head)
{
	list_path *new, hold;
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
 *
 */
void free_pathlist(list_path *head)
{
	list_path *release, *hold;

	if (release == NULL)
		return;

	release = head;

	while (hold != NULL)
	{
		hold = release->next;
		free(release->pathtoken);
		free(release);
		release = hold;
	}
}
