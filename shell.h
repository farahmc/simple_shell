#ifndef SHELL_H
#define SHELL_H

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
