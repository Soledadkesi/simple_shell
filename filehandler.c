#include "main.h"
/**
 * filehandler - executes command in file
 * @filename: filename
 * Return: char **
 */

char **filehandler(char *filename)
{
	char line[100000] = {'\0'};
	int fd;
	int arg_count = 0;
	char **args = NULL;
	/*static char *args[MAX_COMMAND_LENGTH];*/
	size_t nread = 0;
	char *token = NULL;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "./hsh: 0: Can't open ", strlen("./hsh: 0: Can't open "));
		write(2, filename, strlen(filename));
		write(2, "\n", 1);
		exit(127);
	}
	args = malloc(sizeof(char *) * 1000);
	while ((nread = read(fd, line, MAX_ARG_LENGTH)) > 0)
	{
		if (line != NULL)
		{
			token = strtok(line, ";\n");
			while (token != NULL)
			{
				if (token[0] == '#')
				{
					args[arg_count++] = NULL;
					break;
				}
				args[arg_count] = malloc(sizeof(token));
				strcpy(args[arg_count], token);
				token = strtok(NULL, ";\n");
				arg_count++;
			}
		}
	}
	args[arg_count] = NULL;
	close(fd);
	return (args);
}
