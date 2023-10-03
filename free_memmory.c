#include "main.h"
/**
 * free_memmory - free memmory
 * @args: free all memmory
 *
 */
void free_memmory(char **args)
{
	int j = 0;

	while (args[j])
	{
		free(args[j]);
		j++;
	}
	free(args);
}
