#include "main.h"
/**
 * _stderror - standard error printout
 * @str: string
 */
void _stderror(char *str)
{
	write(2, str, str_len(str));

}
