#ifndef _MAIN_H_
#define _MAIN_H_

/** C library functions used **/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/** PROTOTYPES **/
int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_integer(va_list args);

/** STRUCTURE **/

/**
 * struct printer - conects format specifier with its corresponding function.
 * @flag: format specifier.
 * @function: pointer to @flag especific function.
 */

typedef struct printer
{
	char flag;
	int (*function)(va_list);
} printer_t;

#endif /* _MAIN_H_ */
