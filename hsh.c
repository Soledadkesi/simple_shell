#include "main.h"
/**
 * main - This program allows users to enter commands interactively
 * @argc: number of arg
 * @argv: array of arg
 * @env: envoromental variables
 * Return: 0
 */
int main(int argc, char **argv, char **env);
int main(int argc, char **argv, char **env)
{
	static char command[MAX_ARG_LENGTH];
	int i = 1;
	char *command2 = NULL;
	char *args[100000] = {NULL};
	char *token = NULL;
	int arg_count = 0;
	int k = 0;

	(void)env;
	ess.errcode = 0;
	ess.program_name = argv[0];
	if (argc >= 2)
	{

		fileargs(argv[1]);
	}
	else
	{
		while (_stdinput(command))
		{
			command2 = tokenizeOR(command);
			token = strtok(command2, ";&&\n");
			while (token != NULL)
			{
				if (token[0] == '#')
				{
					args[arg_count++] = NULL;
					break;
				}
				args[arg_count++] = token;
				token = strtok(NULL, ";&&\n");
			}
			args[arg_count] = NULL;
			if (*args != NULL)
			{
				k = 0;
				while (args[k])
				{
					i = _execve(args[k]);
					if (i == 0)
					{
						exit(0);
						break;
					}
					k++;
				}
				k = 0;
				arg_count = 0;
				*args = NULL;
			}
			else
			{
				i = _execve(command);
				if (i == 0)
				{
					exit(0);
					break;
				}
			}
		}
	}
	return (0);
}
