#include "main.h"

/**
 * _printf - custom printf that produces output according to a format
 * @format: a character string
 * Return: number of characters printed (excluding the null byte)
*/

int _printf(const char *format, ...)
{
	va_list my_args;
	int i = 1, j = 0, count = 0;

	fmt formats[] = {
		{'c', handle_char}, {'s', handle_string}, {'%', handle_percent},
		{'d', handle_int}, {'i', handle_int}, {'\1', NULL}
	};
	va_start(my_args, format);
	/*If the format is NULL or only contains '%', return 0*/
	if (format == NULL || (format[1] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
		while (format[i])
		{
			if (format[i] == '%')
			{
				i++;

					while (formats[j].my_spec != '\1')
					{
					if (format[i] == formats[j].my_spec)
					{
						count += formats[j].func(my_args);
						break;
					}
					j++;
					}
			}
				else
				{
					_putchar(format[i]);
					count++;
				}
				j = 0;
				i++;
	}
	va_end(my_args);
	return (count);
	}
