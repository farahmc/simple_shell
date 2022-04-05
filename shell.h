#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *file_path(char **argv);
char *_strdup(char *s);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);

#endif
