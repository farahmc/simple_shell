#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

char *file_path(char *command);
char *_getenv(const char *name);
int builtins(char *string);
int forkwaitexec(char **argv);
int _strlen(char *str);
void print_env(char *name);
void flushargv(char **argv, int size);

#endif
