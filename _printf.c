#include "main.h"
#include <unistd.h>

int (*get_print_function(char flag))(va_list);

/**
 * _printf - replica of the printf function
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
		else if (get_print_function(format[i + 1]) != NULL)
		{
			print_count += get_print_function(format[i + 1])(args);
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
 * get_print_function - auxiliary func to retrieve the appropriate print func
 * @flag: format specifier
 *
 * Return: pointer to the print function or NULL
 */
int (*get_print_function(char flag))(va_list)
{
	printer_t arr[] = {
		{'c', print_char},
		{'s', print_string},
		{'i', print_integer},
	};
	int i;

	for (i = 0; arr[i].flag != '\0'; i++)
	{
		if (flag == arr[i].flag)
			break;
	}
	return (arr[i].function); /* Return the appropriate print function */
}
