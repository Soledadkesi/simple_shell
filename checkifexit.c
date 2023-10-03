#include "main.h"
/**
 * checkifexit - exit checker
 * @args: pointer to first arg
 * Return: int 1 or 0
 *
 */
int checkifexit(char **args)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)/*./hsh: 1: exit: Illegal number: HBTN*/
		{
			if (atoi(args[1]) <= 0)
			{
				write(2, "./hsh: 1: exit: Illegal number: ",
						strlen("./hsh: 1: exit: Illegal number: "));
				write(2, args[1], strlen(args[1]));
				write(2, "\n", 1);
				exit(2);
			}
			else
			{
				exit(atoi(args[1]));
			}
		}
		return (0);
	}
	return (5);
}
