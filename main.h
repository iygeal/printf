#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

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
int handle_num(unsigned int n);
int handle_u(va_list my_args);
int handle_o(va_list my_args);
int handle_x(va_list my_args);
int handle_X(va_list my_args);
int print_bin(unsigned int num);
int handle_bin(va_list my_args);
int handle_p(va_list my_args);
int convert_hex(unsigned long int n, char *hex);
void reverse_string(char *str, int length);
int handle_r(va_list my_args);



int _putchar(char c);


#endif
