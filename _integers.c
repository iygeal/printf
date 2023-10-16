#include "main.h"

/**
 * print_number - function that prints and integer
 * @num: argument representing integer to be displayed
 * Return: Returns count of printed characters
*/

int print_number(int num)
{
	int char_count = 0;

	/*special handling for INT_MIN*/
	if (num == INT_MIN)
	{
		_putchar('-');
		_putchar('2');
		num = 147483648;
		char_count = char_count + 2;
	}

	/*general handling for negative numbers*/
	else if (num < 0)
	{
		_putchar('-');
		num *= -1;
		char_count++;
	}

	/*recursive call for numbers greater than 10*/
	if (num >= 10)
		char_count = char_count + print_number(num / 10);

	_putchar(num % 10 + '0');
	char_count++;

	return (char_count);
}

/**
 * handle_d - Function that handles 'd' integer specifiers
 * @my_args: Arguments to pass as integers
 * Return: Returns number of printed characters
 */
int handle_d(va_list my_args)
{
	int char_count = 0;
	/*retrieve the next argument as an integer*/
	int digit = va_arg(my_args, int);

	if (digit < 0)
	{
		_putchar('-');
		char_count++;
		digit = -digit;
	}
	if (digit == 0)
	{
		_putchar('0');
		char_count++;
	}
	else
	{
		char_count = char_count + print_number(digit);
	}
	return (char_count);

}



/**
 * handle_i - Function that handles 'i' integer specifiers
 * @my_args: Arguments to pass as integers
 * Return: Returns number of printed characters
 */
int handle_i(va_list my_args)
{
	int char_count = 0;
	/*retrieve the next argument as an integer*/
	int digit = va_arg(my_args, int);

	if (digit < 0)
	{
		_putchar('-');
		char_count++;
		digit = -digit;
	}
	if (digit == 0)
	{
		_putchar('0');
		char_count++;
	}
	else
	{
		char_count = char_count + print_number(digit);
	}
	return (char_count);
}
