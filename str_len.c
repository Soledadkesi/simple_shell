#include "main.h"
/**
 * str_len - *************
 * @str: string to count
 * Return: int
 */
int str_len(char *str)
{
	if (*str == '\0' || str == NULL)
		return (0);
	return (1 + str_len(++str));
}
