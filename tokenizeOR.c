#include  "main.h"
char *tokenizeOR(char *command)
{
	char *token = NULL;
	token = strtok(command, "|\n");
	return (token);
}
