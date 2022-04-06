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

char *file_path(char **argv);
char *_getenv(const char *name);
int builtins (char *string);
int forkwaitexec(char **argv);
int _cd(char *path);
int _strlen(char *s);
int _env();
void print_env(char *name);
void flushargv(char **argv, int size);

#endif
