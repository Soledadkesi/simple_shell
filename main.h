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



#endif /* end of header*/
