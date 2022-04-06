#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

typedef struct l_list
{
	char *name;
	char *data;
	struct l_list *next;
} list_t;

void print_list(list_t *head)
{
	while (head != NULL)
	{
		printf("%s = %s, head->next = %p\n", head->name, head->data, head->next);
		head = head->next;
	}
}

list_t *addnode(char *env, list_t *head)
{
	list_t *newnode;

	newnode = malloc(sizeof(*newnode));
	if (newnode == NULL)
		return (NULL);
	newnode->next = head;
	newnode->name = strtok(env, "=");
	newnode->data = strtok(NULL, "=");
	head = newnode;
	return (head);
}

int main(void)
{
	int i = 0;
	char *env;
	list_t **head;
	
	*head = NULL;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		env = environ[i];
		*head = addnode(env, *head);
		if (*head == NULL)
			return (1);
		i++;
	}
	print_list(*head);
	return (0);
}
