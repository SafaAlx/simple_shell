#ifndef SHELL_H_INCLUDED
#define SHELL_H_INCLUDED
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



/*---------------------Safa's functions--------------------*/
void int_handler(int i);
void prompt_func(void);
int listen_read(char *);
int chd_launch(char *, char *, char *);
void errors(void);
int next_args(char **);
int update_cmd(char *, char *);
int _main(int argc, char **argv, char **env);
/*---------------------Salma's functions--------------------*/
char *get_path(char **envp);
char **path_params(char *path);
char *get_line(void);
int stringcmp(char *str1, char *str2);
char *stringcat(char *destination, char *source);
long int stringlen(char *p);
int string_split(int argc, char **argv, char *args, char **_path, char **evp);
char *stringconcat(char *str1, char *str2);
char *get_env_value(char **envp, char *var);
int env_print(char **env);
int append(char *cmd);
void buffers1(char *line, char **command);
void buffers2(char **dir, char *combine);
void buffers3(char **tokens, char *buf);
void buffers4(char **tok, char *buf2);
void buffers5(char *dup);


#endif
