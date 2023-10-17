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
#define MAX_COMMAND_LENGTH 100000
/**
 * struct solidad - ==============
 * @kk: =======
 * @kkfunc: ==========
 */
typedef struct solidad
{
	char *kk;
	void (*kkfunc)(char *lolo, const char *ch);
} soliedad;

/**
 * struct cmd_t - getline command
 * @command: pointer
 * @program_name: pname
 * @errcode: err number
 */

typedef struct cmd_t
{
	char *command;
	char *program_name;
	int errcode;
} cmd_t;

cmd_t cmd;
cmd_t ess;
void free_memmory(char **args);
void sigint_handler(int signo);
void _printenv(char **var);
void _stderror(char *str);
int str_len(char *str);
char *tokenizeOR(char *command);
char **filehandler(char *filename);
char *_strcat(char *dest, char *src);
int _putchar(char c);
void _print_number(int n);
void fileargs(char *args);
int checkifexit(char **args);
int checkifenv(char *args);
int _execve(const char *command);
int _strcmp(char *s1, char *s2);
int _stdinput(char *usercommand);
void sigint_handler(int signo);
#endif /* end of header*/
