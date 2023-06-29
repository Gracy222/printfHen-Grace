#ifndef _MAIN_H_
#define _MAIN_H_


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

int (*print_function(char fmt))(va_list);


/**
 * struct linker - links format specifiers to functions
 * @fmt: format specifiers
 * @f: function pointer
 */

typedef struct linker
{
	char fmt;
	int (*f)(va_list);
} linker_p;

#endif /* _MAIN_H_ */
