#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

typedef struct l_list
{
	char *name;
	char *data;
	struct l_list *next;
} list_t;
/**
 * _strlen- counts number of characters in string
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

void print_list(list_t *head)
{
	int lenofname, lenofdata, wf;
	while (head != NULL)
	{
		lenofname = _strlen(head->name);
		lenofdata = _strlen(head->data);
		wf = write(1, head->name, lenofname);
		wf = write(1, "=", 1);
		wf = write(1, head->data, lenofdata);
		wf = write(1, "\n", 1);
		head = head->next;
	}
}

list_t *addnodeatend(char *env, list_t *head)
{
	list_t *newnode, *current;

	current = head;
	while (current != NULL)
	{
		if (current->next == NULL)
			break;
		current = current->next;
	}
	newnode = malloc(sizeof(*newnode));
	if (newnode == NULL)
		return (NULL);
	if (head == NULL)
		head = newnode;
	newnode->next = NULL;
	newnode->name = strtok(env, "=");
	newnode->data = strtok(NULL, "=");
	if (current != NULL)
		current->next = newnode;
	return (head);
}

int main(void)
{
	int i = 0, flag = 0;
	char *env;
	list_t **head;
	
	*head = NULL;
	while (environ[i] != NULL)
	{
		env = environ[i];
		*head = addnodeatend(env, *head);
		if (*head == NULL)
			return (1);
		i++;
	}
	print_list(*head);
	return (0);
}
