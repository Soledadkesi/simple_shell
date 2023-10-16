#include "main.h"
int _execve(const char *command);
/**
 * _execve - exec ve
 * @command: command
 * Return: int
 */
int _execve(const char *command)
{
	int pid;
	char *args[MAX_COMMAND_LENGTH];
	int arg_count = 0;
	int check = 5;
	int exit_status;

	char *token = strtok((char *)command, " \"\'\t\r\n");

	while (token != NULL && arg_count < MAX_COMMAND_LENGTH - 1)
	{
		if (token[0] == '#')
		{
			args[arg_count++] = NULL;
			break;
		}
		args[arg_count++] = token;
		token = strtok(NULL, " \"\'\t\r\n");
	}
	args[arg_count] = NULL;
	if (args[0] == NULL)
	{
		return (1);
	}

	check = checkifenv(args[0]);
	if (check != 5)
		return (check);
	check = checkifexit(args);
	if (check != 5)
		return (check);

	pid  = fork();

	if (pid == 0)
	{
		if (strcmp(args[0], "ls") == 0)
		{
			execve("/bin/ls", args, environ);
		}
		else if (strcmp(args[0], "echo") == 0)
		{
			execve("/bin/echo", args, environ);
		}
		else
		{
			execve(args[0], args, environ);
		}
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status  != 0 && !isatty(STDIN_FILENO))
			{
				exit(exit_status);
			}
		}
	}
	return (1);
}
