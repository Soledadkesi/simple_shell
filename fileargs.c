#include "main.h"
/**
 * fileargs - ======
 * @args: =====
 */
void fileargs(char *args)
{
	char **arr = NULL;
	int k = 0;
	int i = 1;

	arr = filehandler(args);
	if (arr != NULL)
	{
		k = 0;
		while (arr[k] != NULL)
		{
			i = _execve(arr[k]);
			if (i == 0)
			{
				if (arr)
					free_memmory(arr);
				exit(0);
				break;
			}
			k++;
		}
		k = 0;
		free_memmory(arr);
	}
}
