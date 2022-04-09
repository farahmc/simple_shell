#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcnt1.h>

extern char **environ;

/**
 * struct list_path - a singly linked list containing pointers to strings
 * @pathtoken: pointer to string which is a segment of the PATH
 * @next: a pointer to the next node
 */
typedef struct list_path
{
	char *pathtoken;
	struct list_path *next;
} list_path;

void sighandler(int sig_num);
int prompt(void);
char *readaline(void);
int errormessage(char *firstarg);
int processinput(char *buffer);
int buffertokens(char **argv, char *buffer);
void freeargv(char **argv);
char *findpath(char *command, char *error);
int break_up_path(char *envpath, list_path **head);
int add_node_pathlist(list_path **head, char *token);
void free_pathlist(list_path *head);
int checkpath(char *pathname);
char *_getenv(const char *name);
void print_env(char *name);
int forkwaitexec(char **argv);
void _strcpy(char *dest, char *src);
char *_strdup(char *string);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int builtins(char *argv[]);
int _env(void);
int _cd(char *argv[]);
int _setenv(char *argv[20]);
int _unsetenv(char *argv[20]);
int _help(char *string);
int rw(int fd);

#endif
