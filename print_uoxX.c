#include "main.h"

/**
 * handle_num -  Function to print an integer digit by digit
 * @n: The integer value to print
 * Return: The number of characters printed
*/

int handle_num(unsigned int n)
{
	int count = 0;

	if (n >= 10)
	{
		count = count + handle_num(n / 10);
	}
		_putchar(n % 10 + '0');
		count++;

	return (count);
}

/**
 * handle_u - Function to handle 'u' specifier
 * @my_args: number of arguments
 * Return: The number of characters printed
*/

int handle_u(va_list my_args)
{
	unsigned int n = va_arg(my_args, unsigned int);

	int count = handle_num(n);

	return (count);

}

/**
 * handle_o - Function to handle 'o' specifier
 * @my_args: number of arguments
 * Return: The number of characters printed
*/

int handle_o(va_list my_args)
{
	int i;
	int count = 0;
	unsigned int n = va_arg(my_args, unsigned int);
	char buffer[12];

	do {
		buffer[count] = "01234567"[n % 8];
		n /= 8;
		count++;
	} while (n > 0);

	for (i = count - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}

	return (count);
}

/**
 * handle_x - Function to handle 'x' specifier
 * @my_args: number of arguments
 * Return: The number of characters printed
*/

int handle_x(va_list my_args)
{
	int i;
	int count = 0;
	unsigned int n = va_arg(my_args, unsigned int);
	char buffer[9];

	do {
		buffer[count] = "0123456789abcdef"[n % 16];
		n /= 16;
		count++;
	} while (n > 0);
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}
	return (count);
}

/**
 * handle_X - Function to handle 'X' specifier
 * @my_args: number of arguments
 * Return: The number of characters printed
*/

int handle_X(va_list my_args)
{
	int i;
	int count = 0;
	unsigned int n = va_arg(my_args, unsigned int);
	char buffer[9];

	do {
		buffer[count] = "0123456789ABCDEF"[n % 16];
		n /= 16;
		count++;
	} while (n > 0);
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}
	return (count);
}

