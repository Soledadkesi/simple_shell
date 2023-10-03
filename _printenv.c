#include "main.h"
/**
 * _printenv - A function that print envirimental variables
 * @var: environ
 *
 */
void _printenv(char **var)
{
	int i = 0;

	while (var[i] != NULL)
	{
		write(STDOUT_FILENO, var[i], str_len(var[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
