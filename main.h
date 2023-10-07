#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <error.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
#define MAX_ARG_LENGTH 100000
void free_memmory(char **args);
void _printenv(char **var);
int str_len(char *str);
char *tokenizeOR(char *command);
char **filehandler(char *filename);
char *_strcat(char *dest, char *src);
void fileargs(char *args);
int checkifexit(char **args);
int checkifenv(char *args);
int _execve(const char *command);
int _strcmp(char *s1, char *s2);
int _stdinput(char *usercommand);
#endif /* end of header*/
