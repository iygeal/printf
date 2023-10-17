#include "main.h"

/**
 * convert_hex - converts an unsigned long int to a hex string
 * @n: the number to convert
 * @hex: the string to store the converted number
 * Return: the length of the converted string
*/

int convert_hex(unsigned long int n, char *hex)
{
	int i = 2;

	while (n != 0)
	{
		hex[i++] = "0123456789abcdef"[n % 16];
		n = n / 16;
	}
	return (i);
}

/**
 * reverse_string - reverse a string
 * @str: the string to reverse
 * @length: the length of the string
*/

void reverse_string(char *str, int length)
{
	int start = 2;
	int end = length - 1;

	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}


/**
 * handle_p - Handle the %p conversion specifier
 * @my_args: A va_list from which to retrieve the argument
 * Return: The number of characters printed
 */
int handle_p(va_list my_args)
{
	int i;
	void *adr = va_arg(my_args, void *);

	unsigned long int n = (unsigned long int)adr;
	int num_digits = sizeof(void *) * 2 + 2;
	char *ptr_Arr = (char *)malloc(num_digits + 1);

	if (ptr_Arr == NULL)
	{
		return (-1);
	}
	if (adr == NULL)
	{
		char *null_msg = "NULL PTR";
		char *c = null_msg;

		while (*c)
		{
			_putchar(*c++);
		}
		free(ptr_Arr);
		return (8);
	}
	ptr_Arr[0] = '0';
	ptr_Arr[1] = 'x';

	i = convert_hex(n, ptr_Arr);
	reverse_string(ptr_Arr, i);

		for (i = 0; i < num_digits && ptr_Arr[i] != 0; i++)
		{
			_putchar(ptr_Arr[i]);
		}
		return (i);
}
