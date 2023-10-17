#ALX Africa

![alxx](https://github.com/iygeal/printf/assets/120268850/f3a786e1-6a56-4d73-a02e-3d3bea56451d)

#Simple manual implementation of the printf function in C.

#printf()

The printf function is used to print formatted text to the standard output. It is included in the stdio.h file of the standard library.

The format string contains zero or more directives, which can be either literal characters or encoded conversion specifications that describe how to format arguemt(s) in the output.

The general format of printf() function is as follows:

`int printf(const char *format, ...);`

In the above, `format` is a string that contains text to be printed to the standard output. It can optionally contain embedded format tags that are replaced by values specified in subsequent arguments and formated as requested. The `...` is an ellipsis which indicates that the function can take a variable number of arguments.

When printf is run alone, it returns an integer value which represents the number of characters transmitted to the standard output stream. If output/encoding error occurs, printf returns a negative value.

*_printf*
===

My partner and I created a function that imitates the printf function.

####main.h
This contains all the function prototypes used in the manual implementation of the printf function. It also contains a typedef declaration of struct format. This structure has two members: 'my_spec', which is a character that represents the format specifier, and 'fun', which is a pointer to the function that should be called when the format specifier is encountered in the _printf() function.

It also contains some header files from the C standard library - notably, `stdarg.h` - which are used in this implementation.

The header file is appropriately guarded to avoid multiple definitions of the same header file.

`#ifndef MAIN_H
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
char *_rot13(char *str);
int handle_R(va_list my_args);



int _putchar(char c);


#endif`

##Below are functions used in this implementation:

###int _printf(const char *format, ...):
Custom printf that produces output according to a format.

###int handle_d(va_list my_args): 
Function that handles 'd' integer specifiers and prints the corresponding integer.

###int handle_i(va_list my_args): 
Function that handles 'i' integer specifiers and prints the corresponding integer.

###int handle_format(const char *format, int *i, va_list my_args): 
Handles the format specifier in the given format string.

###int _putchar(char c): 
Writes the character c to stdout.

###int handle_bin(va_list my_args): 
Function that handles 'b' specifier and prints the binary representation of an unsigned integer.

###int print_bin(unsigned int num): 
Auxiliary function that prints the binary representation of an unsigned integer.

###int convert_hex(unsigned long int n, char *hex): 
Converts an unsigned long int to a hex string.

###void reverse_string(char *str, int length): 
Reverses a string.

###int handle_p(va_list my_args):
Handles the %p conversion specifier and prints the memory address.

###int handle_r(va_list my_args): 
Handles the %r conversion specifier and prints a string in reverse.

###char *_rot13(char *str): 
Encodes a string using ROT13 encryption.

###int handle_R(va_list my_args): 
Handles the %R conversion specifier and prints a string encoded in ROT13.

###int handle_num(unsigned int n): 
Function to print an integer digit by digit.

###int handle_u(va_list my_args): 
Function to handle 'u' specifier and print an unsigned integer.

###int handle_o(va_list my_args): 
Function to handle 'o' specifier and print an octal representation of an unsigned integer.

###int handle_x(va_list my_args): 
Function to handle 'x' specifier and print a hexadecimal representation (lowercase) of an unsigned integer.

###int handle_X(va_list my_args): 
Function to handle 'X' specifier and print a hexadecimal representation (uppercase) of an unsigned integer.

###int handle_char(va_list my_args): 
Function that handles 'c' specifier and prints a character.

###int handle_string(va_list my_args): 
Function that handles 's' specifier and prints a string.

###int handle_percent(va_list my_args): 
Handles the '%%' specifier and prints a '%' character.


