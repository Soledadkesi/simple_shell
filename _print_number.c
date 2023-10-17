#include "main.h"

/**
 * _print_number -  =========
 * @n: ===========
 */

void _print_number(int n)
{
	unsigned int num = n;

	if (n < 0)
	{
		_putchar('-');
		num = -num;
	}

	if ((num / 10) > 0)
		_print_number(num / 10);

	_putchar((num % 10) + '0');
}
