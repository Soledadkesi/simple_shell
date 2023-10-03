#include "main.h"
/**
 * _strcat - join two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	if (src == NULL || dest == NULL)
		return (NULL);
	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
