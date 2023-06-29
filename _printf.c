#include "main.h"
#include <unistd.h>


/**
 * _printf - self made printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i;
	int print_count = 0;
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1); /* Write the character */
						/* to the output */
			print_count++; /* Increment the print count */
		}
		else if (format[i + 1] == '\0')
			return (-1);
		else if (format[i + 1] == '%')
		{
			write(1, "%", 1); /* Write the '%' character */
					/* to the output */
			print_count++; /* Increment the print count */
			i++;
		}
		else if (print_function(format[i + 1]) != NULL)
		{
			print_count += print_function(format[i + 1])(args);
			/* Call the appropriate print function and update the print count */
			i++;
		}
		else
		{
			write(1, &format[i], 1); /* Write the character */
						/* to the output */
			print_count++; /* Increment the print count */
		}
	}
	va_end(args);
	return (print_count); /* Return the total num of characters printed */
}


/**
 * print_function - a function that collects the specific print function
 * @fmt: Argument - act as a format specifier
 *
 * Return: point
 */


int (*print_function(char fmt))(va_list)
{
	linker_p arr[] = {
		{'c', print_char},
		{'s', print_string},
		{'i', print_integer},
		{'d', print_integer},
		{'\0', NULL}
	};
	int index;

	for (index = 0; arr[index].fmt != '\0'; index++)
	{
		if (fmt == arr[index].fmt)
		{
			break;
		}
	}
	return (arr[index].f); /* Return the appropriate print function */
}
