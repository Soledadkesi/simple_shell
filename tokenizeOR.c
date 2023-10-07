#include  "main.h"
/**
 * tokenizeOR - tokenize OR || operator
 * @command: command
 * Return: return command
 */
char *tokenizeOR(char *command)
{
	char *token = NULL;

	token = strtok(command, "|\n");
	return (token);
}
