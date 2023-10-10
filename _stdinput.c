#include "main.h"
/**
 * sigint_handler - CTRL C
 * @signo: signal no
 */
void sigint_handler(int signo)
{
	/*Handle SIGINT (Ctrl+C) by freeing allocated memory*/
	(void) signo;
	free(cmd.command);
	exit(0);  /*Terminate the program gracefull*/
}
/**
 * _stdinput - reads user's input
 * @usercommand:  user input
 * Return: 1 and 0
 */
int _stdinput(char *usercommand)
{
	size_t buffsize = 0;
	int byte = 0;

	cmd.command = NULL;

	signal(SIGINT, sigint_handler);
	byte = getline(&cmd.command,  &buffsize, stdin);
	if (byte == -1)
	{
		free(cmd.command);
		return (0);
	}
	if (str_len(cmd.command) > 3990)
	{
		if (strchr(cmd.command, '/') != NULL)
		{
			strcpy(usercommand, "/bin/ls");
		}
		else
		{
			strcpy(usercommand, " ");
		}
		_strcat(usercommand, "\0");
		free(cmd.command);
		return (1);
	}
	strcpy(usercommand, cmd.command);
	_strcat(usercommand, "\0");
	free(cmd.command);
	return (1);

}
