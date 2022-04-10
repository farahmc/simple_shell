#include "shell.h"

/**
 * _setenv - adds or moddifies an env var
 * @node: the node to add or change
 * @head: ptr to the head of the linked list
 * Return: 0 on success, 1 on fail
 */

int _setenv(envlist_t *node, envlist_t **head)
{
	int i = 0, flag = 0;
	char *current_env = NULL, *newnode = NULL;
	char *nodename = _strdup(node->name);
	envlist_t *temp = NULL;

	if (*head == NULL)
		return (1);
	temp = *head;
	while (temp != NULL)
	{
		current_env = _strdup(temp->name);
		i = 0;
		while (current_env[i] != '\0')
		{
			if (nodename[i] != current_env[i])
				flag = 1;
			i++;
		}
		if (flag == 0)
		{
			printf("node found, changing data\n");
			free(current_env);
			temp->data = node->data;
			free(nodename);
			return (0);
		}
		temp = temp->next;
	}
	free(current_env);
	printf("node not found, adding node\n");
	newnode = _strcat(node->name, "=");
	newnode = _strcat(newnode, node->data);
	flag = add_node_at_end_of_envlist(newnode, head);
	if (flag == 1)
		return (1);
	return (0);
}

/**
 * _unsetenv - removes an environmental variable
 * @nodename: its name
 * @head: ptr to the head node
 * Return: 0 on success or 1 on fail
 */

int _unsetenv(char *nodename, envlist_t **head)
{
	envlist_t *current, *temp;
	char *current_env = NULL;
	int i = 0, flag = 0;

	temp = *head;
	while (temp != NULL)
	{
		flag = 0;
		current_env = _strdup(temp->name);
		i = 0;
		while (current_env[i] != '\0')
		{
			if (nodename[i] != current_env[i])
				flag = 1;
			i++;
		}
		if (flag == 0)
		{
			printf("node to remove found\n");
			free(current_env);
			current->next = temp->next;
			free(temp->name);
			free(temp->data);
			free(temp);
			return (0);
		}
		current = temp;
		temp = temp->next;
	}
	free(current_env);
	printf("node to delete not found");
	return (1);
}

/**
 * free_env - frees up the allocated memory
 * @head: a ptr to the list
 * Return: pointer to member if found
*/

void free_env(envlist_t **head)
{
	envlist_t *temp_node = NULL, *ptr = NULL;

	ptr = *head;
	while (ptr != NULL)
	{
		temp_node = ptr;
		ptr = ptr->next;
		free(temp_node->name);
		free(temp_node->data);
		free(temp_node);
	}
}

/**
 * _getenvfromllist - finds the value from the env name
 * @name: the environment name we are looking for
 * @head: ptr to the head node of the linked list
 * Return: NULL or the value of the env found
 */

char *_getenvfromllist(const char *name, envlist_t *head)
{
	int i = 0, loopcount = 0, flag = 0;
	envlist_t *current_node = NULL;
	char *current_env = NULL, *current_name, *current_data;

	while (head != NULL)
	{
		loopcount++;
		flag = 0;
		current_env = _strdup(head->name);
		i = 0;
		while (current_env[i] != '\0')
		{
			if (name[i] != current_env[i])
				flag = 1;
			i++;
		}
		if (flag == 0)
		{
			free(current_env);
			return (head->data);
		}
		head = head->next;
		free(current_env);
	}
	return (NULL);
}

/**
 * print_env_list - prints the env using a linked list
 * @head: ptr to the head of the llist
 * Return: is void
 */
void print_env_list(envlist_t *head)
{
	int lenofname, lenofdata, wf;
	envlist_t *temp;

	temp = head;
	while (temp != NULL)
	{
		lenofname = _strlen(temp->name);
		lenofdata = _strlen(temp->data);
		wf = write(1, temp->name, lenofname);
		wf = write(1, "=", 1);
		wf = write(1, temp->data, lenofdata);
		wf = write(1, "\n", 1);
		temp = temp->next;
	}
}

/**
 * add_node_at_end_of_envlist - adds an env node at the end of a linked list
 * @env: the env to add
 * @head: a ptr to the list head node
 * Return: 0 on success
 */

int add_node_at_end_of_envlist(char *env, envlist_t **head)
{
	envlist_t *newnode, *current;

	current = *head;
	while (current != NULL)
	{
		if (current->next == NULL)
			break;
		current = current->next;
	}
	newnode = malloc(sizeof(*newnode));
	if (newnode == NULL)
		return (1);
	if (*head == NULL)
		*head = newnode;
	else
		current->next = newnode;
	newnode->next = NULL;
	newnode->name = _strdup(strtok(env, "="));
	newnode->data = _strdup(strtok(NULL, "="));
	return (0);
}

/**
 * create_env_list - creates a linked list of the environ members
 * @head: ptr to the head node
 * Return: 0 on success
 */

int create_env_list(envlist_t **head)
{
	int i = 0, flag = 0, len = 0;
	char *env = NULL, *temp = NULL;
	envlist_t *node;

	while (environ[i] != NULL)
	{
		env = _strdup(environ[i]);
		flag = add_node_at_end_of_envlist(env, head);
		if (flag != 0)
		{
			free(env);
			return (1);
		}
		i++;
	}
	free(env);
	return (0);
}

/**
 * main - our main
 * Return: 0 on success
 */

/*
int main(void)
{
	int check = 0;
	envlist_t *env_head = NULL, *test_node = NULL;
	char *env = NULL;

	check =	create_env_list(&env_head);
	if (check == 1)
	{
		perror("ENV not found");
		return (1);
	}

	env = _getenvfromllist("PWD", env_head);
	printf("PWD = %s\n", env);
	env = _getenvfromllist("OLDPWD", env_head);
	printf("OLDPWD = %s\n", env);

	env = _strdup("NEW=new_data");
	check = add_node_at_end_of_envlist(env, &env_head);
	if (check == 1)
		printf("add_node_failed");
	check = 0;
	env = _strdup("NEW");
	check = _unsetenv(env, &env_head);
	if (check == 1)
		printf("_unsetenv failed");

	test_node = malloc(sizeof(*test_node));
	test_node->name = _strdup("TEST");
	test_node->data = _strdup("tets data");
	test_node->next = NULL;

	check = 0;
	check = _setenv(test_node, &env_head);
	if (check == 1)
		printf("_setenv failed");
	print_env_list(env_head);

	check = 0;
	test_node->data = _strdup("test data");
	check = _setenv(test_node, &env_head);
	if (check == 1)
		printf("_setenv failed to modify");
	print_env_list(env_head);
	return (0);
}
*/
