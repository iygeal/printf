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


/**
 * _rot13 - encodes a string using rot 13
 * @str: the string to encode
 * Return: the result
*/

char *_rot13(char *str)
{
	int i, j;
	char *src = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *dest = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	/*Allocate memory for the new string*/
	char *new_str = malloc(strlen(str) + 1);

	if (new_str == NULL)
	{
		return (NULL);
	}

	/*copy the input string to the new string*/
	strcpy(new_str, str);

	/*Encode the new string using ROT13*/
	for (i = 0; new_str[i]; i++)
	{
		for (j = 0; src[j]; j++)
		{
			if (new_str[i] == src[j])
			{
				new_str[i] = dest[j];
				break;
			}
		}
	}
	return (new_str);
}

/**
 * handle_R - handle the %R conversion specifier
 * @my_args: A va_list from which to retrieve the argument
 * Return: number of characters printed
*/

int handle_R(va_list my_args)
{
	int i, len;
	char *rot_str;
	char *str = va_arg(my_args, char *);

	if (str == NULL)
	{
		return (0);
	}
	rot_str = _rot13(str);

	if (rot_str == NULL)
	{
		return (-1);
	}
	len = strlen(rot_str);

	for (i = 0; i < len; i++)
	{
		_putchar(rot_str[i]);
	}
	free(rot_str);
	return (len);
}
