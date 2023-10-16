#include "main.h"
/**
 * handle_d - Function that handles 'd' integer specifiers
 * @my_args: Arguments to pass as integers
 * Return: Returns number of printed characters
 */
int handle_d(va_list my_args)
{
	int i, char_count = 0, temp = 0;
	int digit_count = 0;
	char *buffer;
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
		temp = digit;
		while (temp != 0)
		{
			temp /= 10;
			digit_count++;
		}
		buffer = malloc(digit_count * sizeof(char));
		if (buffer == NULL)
			return (-1);
	}
		for (i = 0; i < digit_count; i++)
		{
			buffer[i] = digit % 10 + '0';
			digit /= 10;
			char_count++;
		}
		for (i = digit_count - 1; i >= 0; i--)
		{
			_putchar(buffer[i]);
		}
		free(buffer);
	return (char_count);
}

/**
 * handle_i - Function that handles 'i' integer specifiers
 * @my_args: Arguments to pass as integers
 * Return: Returns number of printed characters
 */
int handle_i(va_list my_args)
{
	int i, char_count = 0, temp = 0;
	int digit_count = 0;
	char *buffer;
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
		temp = digit;
		while (temp != 0)
		{
			temp /= 10;
			digit_count++;
		}
		buffer = malloc(digit_count * sizeof(char));
		if (buffer == NULL)
			return (-1);
	}
		for (i = 0; i < digit_count; i++)
		{
			buffer[i] = digit % 10 + '0';
			digit /= 10;
			char_count++;
		}
		for (i = digit_count - 1; i >= 0; i--)
		{
			_putchar(buffer[i]);
		}
		free(buffer);
	_putchar('\n');
	return (char_count);
}
