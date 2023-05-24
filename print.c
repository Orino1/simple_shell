#include "shell.h"
/**
 * print_number -Printing Unsigned Int Putchar
 * @n: Unisigned Int
 * Return: Void
 */
void print_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}
/**
 * print_number_in - Printing Number Putchar
 * @n:Integer
 * Return: void
 */
void print_number_in(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}

