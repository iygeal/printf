#include "main.h"
/**
 * handle_bin - Function that handles 'b' specifier
 * @my_args: Arguments passed
 * Return: Number of characters printed
 */
int handle_bin(va_list my_args)
{
	unsigned int num = va_arg(my_args, unsigned int);
	int count = 0;

	count = print_bin(num) + count;
	return (count);
}
/**
 * print_bin - Auxiliary function that prints 'b' representation
 * @num: Binary number to be printed
 * Return: Returns number of printed characters
 */
int print_bin(unsigned int num)
{
	int count = 0;

	if (num / 2)
		count = print_bin(num / 2) + count;
	_putchar((num % 2) + '0');
	count++;
	return (count);
}
