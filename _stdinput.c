#include "main.h"
/**
 * _stdinput - reads user's input
 * @usercommand:  user input
 * Return: 1 and 0
 */
int _stdinput(char *usercommand)
{
	size_t buffsize = 0;
	char *command = NULL;
	size_t byte = 0;

	byte = getline(&command,  &buffsize, stdin);
	if (byte == -1)
	{
		free(command);
		return (0);
	}
	if (str_len(command) > 3990)
	{
		if (strchr(command, '/') != NULL)
		{
			strcpy(usercommand, "/bin/ls");
		}
		else
		{
			strcpy(usercommand, " ");
		}
		_strcat(usercommand, "\0");
		free(command);
		return (1);
	}
	strcpy(usercommand, command);
	_strcat(usercommand, "\0");
	free(command);
	return (1);

}
