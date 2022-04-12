#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

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
void prompt(void);
char *_strtok(char *string, const char *delim);
char *readinput(void);
int processinput(char *buffer, char *argv[], char *progName, int cmds);
int buffertokens(char **argv, char *buffer);
char *findpath(char *command, char *error);
int break_up_path(char *envpath, list_path **head);
int add_node_pathlist(list_path **head, char *token);
void free_pathlist(list_path *head);
int checkpath(char *pathname);
char *_getenv(const char *name);
void print_env(char *name);
void forkwaitexec(char **argv);
void _strcpy(char *dest, char *src);
char *_strdup(char *string);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int builtins(char *argv[], char *buffer);
int _env(void);
void _cd(char *argv[]);
int _setenv(char *argv[20]);
int _unsetenv(char *argv[20]);
int _help(char *string);
int rw(int fd);
int find_builtin(char *command);
void error_print(char *progname, char *command, int cmdcount);

#endif
