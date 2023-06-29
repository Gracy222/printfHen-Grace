#include "main.h"
#include <unistd.h>

/**
 * print_string - prints a string
 * @args: variable arguments list
 *
 * Return: the total number of characters printed
 */
int print_string(va_list args)
{
	char *string = va_arg(args, char *); /* Retrieve the string argument */
					/*from the variable arguments list */
	int count = 0; /* Initialize the character count to 0 */

	if (string == NULL)
		string = "(null)";

	while (*string)
	{
		write(1, string, 1); /* Write each character of */
				/* the string to the output */
		string++;
		count++;
	}

	return (count); /* Return the total number of characters printed */
}
