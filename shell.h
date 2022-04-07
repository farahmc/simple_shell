#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

typedef struct list_path
{
	char *pathtoken;
	struct list_path *next;
} list_path;

char *file_path(char *command);
char *_getenv(const char *name);
char *_strdup(char *string);
int add_node_pathlist(list_path **head, char *string);
int builtins (char *string);
int forkwaitexec(char **argv);
int _cd(char *path);
int _strlen(char *s);
int _env();
int break_up_path(char *envpath, list_path **head);
size_t print_pathlist(list_path *head);
void print_env(char *name);
void free_pathlist(list_path *head);

#endif
