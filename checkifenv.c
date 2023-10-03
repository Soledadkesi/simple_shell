#include "main.h"
/**
 * checkifenv - check if env was passed
 * @args: arguement
 * Return: 0 & 1
 *
 */
int checkifenv(char *args)
{
	if (_strcmp(args, "env") == 0)
	{
		_printenv(environ);
		return (1);
	}
	if (_strcmp(args, "printenv") == 0)
	{
		_printenv(environ);
		return (1);
	}
return (5);
}
