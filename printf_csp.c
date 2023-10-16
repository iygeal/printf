#include "main.h"

/**
 * handle_char - handles a character
 * @my_args: arguments to be passed
 * Return: number of characters printed
*/

/*Function to handle 'c' specifier*/
int handle_char(va_list my_args)
{
	char c;
	int c_count = 0;

	c = va_arg(my_args, int);
	_putchar(c);
	c_count++;

	return (c_count);
}

/**
 * handle_string - handle a string
 * @my_args: arguments to be passed
 * Return: number of characters printed
*/

int handle_string(va_list my_args)
{
	char *str;
	char *p;
	int str_count = 0;

	/*Get the next argument as a string*/
	str = va_arg(my_args, char *);

	/*If the string is NULL, print "null"*/
	if (str == NULL)
	{
		str = "null";
	}

  /*Print the string character by character*/
	for (p = str; *p != '\0'; p++)
	{
		_putchar(*p);
		str_count++;
	}

	_putchar('\n');
	return (str_count);
}

/**
 * handle_percent - handles the '%%' specifier (prints a '%')
 * @my_args: arguments to be passed
 * Return: number of characters printed
*/

int handle_percent(va_list my_args)
{
	int count = 0;

	/*This prevents compiler warnings about unused variables*/
	(void) my_args;

	_putchar('%');
	count++;

	return (count);

}
