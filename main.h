#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct format - the format specifier character
 * @my_spec: pointer to the function that should be called
 * @func: declares a pointer function
*/

typedef struct format
{
	char my_spec;
	int (*func)(va_list);
} fmt;

int handle_format(const char *format, int *i, va_list my_args);
int _printf(const char *format, ...);
int handle_char(va_list my_args);
int handle_string(va_list my_args);
int handle_percent(va_list my_args);
int handle_d(va_list my_args);
int handle_i(va_list my_args);


int _putchar(char c);


#endif
