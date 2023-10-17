#include "main.h"

/**
 * handle_p - Handle the %p conversion specifier
 * @my_args: A va_list from which to retrieve the argument
 * Return: The number of characters printed
 */
int handle_p(va_list my_args)
{
	int y;
	int i = 0;
	char ptr_Arr[20];
	void *adr = va_arg(my_args, void *);

	unsigned long int n = (unsigned long int)adr;
	unsigned long int temp = n;

	if (adr == NULL)
	{
		char *null_msg = "NULL PTR";
		char *c = null_msg;

		while (*c)
		{
			_putchar(*c++);
		}
		return (8);
	}
	ptr_Arr[0] = '0';
	ptr_Arr[1] = 'x';
	for (y = 19; y >= 2 && temp; y--)
	{
		ptr_Arr[y] = "0123456789abcdef"[temp % 16];
		temp = temp / 16;
	}

	for (i = 0; i < 20; i++)
	{
		_putchar(ptr_Arr[i]);
	}
	return (20 - y);
}
