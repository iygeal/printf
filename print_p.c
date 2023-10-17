#include "main.h"

/**
 * print_p - function to recursively print hexadecimal
 * @n: the unsigned long integer to be converted and printed
 * Return: the number of characters printed
*/

int print_p(unsigned long int n)
{
	long int x, count = 0;
	unsigned long int hex_digit;
	/*recursively divide n by 2 until n is 0 or 1*/
	if (n > 15)
	{
		count += print_p(n / 16);
	}
	hex_digit = n % 16;

	_putchar(hex_digit < 10 ? hex_digit + '0' : hex_digit - 10 + 'a');
	count++;

	return (count);
}

/**
 * handle_p - Handle the %p conversion specifier
 * @my_args: A va_list form which to retrieve the argument
 * Return: The number of characters printed
*/

int handle_p(va_list my_args)
{
	int count = 0;
	void *adr = va_arg(my_args, void *);

	_putchar('0');
	_putchar('x');
	int count = print_p((unsigned long)adr);
	return (count + 2);

}

/**
 * _printf - function that produces output according to a format
 * @format: a character string
 * Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	int count = 0;
	va_list my_args;

	va_start(my_args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'p':
				{
					count = count + handle_p(my_args);
					break;
				}
				default:
				return (-1);
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(my_args);
	return (count);
}
