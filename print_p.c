#include "main.h"

/**
 * handle_p - Handle the %p conversion specifier
 * @my_args: A va_list from which to retrieve the argument
 * Return: The number of characters printed
 */
int handle_p(va_list my_args)
{
	int j;
	int i = 2;
	char ptr_Arr[20] = {0};
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

	while (temp != 0)
	{
		ptr_Arr[i++] = "0123456789abcdef"[temp % 16];
		temp = temp / 16;
	}
		for (j = 2; j < (i / 2); j++)
		{
			char temp = ptr_Arr[j];

			ptr_Arr[j] = ptr_Arr[i - j + 1];
			ptr_Arr[i - j + 1] = temp;
		}
		for (i = 0; i < 20 && ptr_Arr[i] != 0; i++)
		{
			_putchar(ptr_Arr[i]);
		}
		return (i);
}
