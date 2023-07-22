#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <assert.h>
#define SIZEBUFFER 1024
char *stringconcat(char *s1, char *s2);
char *get_env_value(char **envp, char *variable);
int stringcmp(char *s1, char *s2);
char *stringcat(char *dest, char *src);
void int_handler(int i);
void prompt_func(void);
int listen_read(char *);
int string_split(int, char **, char *, char **, char **);
int chd_launch(char **, char *, char **);
void errors(void);
long int stringlen(char *);
int next_args(char **);
char *get_path(char **);
char **path_params(char *);
int update_cmd(char **, char **);
int append(char *);
int env_print(char **);
int _main(int argc, char **argv, char **env);
#endif
