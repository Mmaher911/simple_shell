#include "main.h"

/**
 * print_num - Prints integers using _putchar
 * @n: Unsigned integer to be printed
 */

void print_num(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_num(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * print_num_int - Prints using _putchar function
 * @n: number of integers to be printed
 */

void print_num_int(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_num(x / 10);

	_putchar(x % 10 + '0');
}
