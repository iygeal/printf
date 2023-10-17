#include "main.h"

/**
 * handle_r - Handle the %r conversion specifier
 * @my_args: A va_list from which to retrieve the argument
 * Return: The number of characters printed
*/

int handle_r(va_list my_args)
{
	char *str = va_arg(my_args, char *);
	int i;
	int len = strlen(str);

	if (str == NULL)
	{
		return (0);
	}

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(str[i]);
	}

	return (len);
}
