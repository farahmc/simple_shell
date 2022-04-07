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

int buffertokens(char **argv, char *buffer);
void freeargv(char **argv);
char *file_path(char *command);
int break_up_path(char *envpath, list_path **head);
void free_pathlist(list_path *head);
char *_getenv(const char *name);
void print_env(char *name);
int forkwaitexec(char **argv);
void _strcpy(char *dest, char *src);
char *_strdup(char *string);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int builtins (char *string);
int _env();
int _cd(char *path);
int error(char *firstarg);

#endif
