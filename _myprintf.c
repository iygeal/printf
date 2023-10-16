#include "main.h"

/**
 * handle_format - handle the format specifier
 * @format: the format string to process
 * @i: the current index in the format string list
 * @my_args: the list of arguments
 * Return: the number of characters printed
*/

int handle_format(const char *format, int *i, va_list my_args)
{
	int j = 0, count = 0;
	int valid_specifier = 0;

  /*Array of format specification structures*/
	fmt formats[] = {
	{'c', handle_char}, {'s', handle_string},
	{'%', handle_percent}, {'d', handle_d}, {'i', handle_i}, {'\0', NULL}
	};

  /*Iterate over the format specifier array*/
	while (formats[j].my_spec != '\0')
	{
    /*If the format specifier matches, call the corresponding function*/
		if (format[*i] == formats[j].my_spec)
		{
			count = count + formats[j].func(my_args);
			valid_specifier = 1;
			break;
		}
		j++;
	}
    /*If no match found, print the '%' character and the invalid specifier*/
	if (valid_specifier == 0)
	{
		_putchar('%');
		_putchar(format[*i]);
		count = count + 2;
	}
	return (count);
}

/**
 * _printf - custom printf that produces output according to a format
 * @format: a character string
 * Return: number of characters printed (excluding the null byte)
*/

int _printf(const char *format, ...)
{
	va_list my_args;
	int i = 0, count = 0;

	va_start(my_args, format);
	/*If the format is NULL or only contains '%', return -1*/
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
  /*Iterate over the format string*/
	while (format && format[i])
	{
		/*If current character is '%', process the format specifier*/
		if (format[i] == '%')
		{
		i++;
		count = count + handle_format(format, &i, my_args);
		}
		else
		{
			/*If current character is not '%', print it as is*/
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(my_args);
	return (count);

}
