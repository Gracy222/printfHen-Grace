#include "main.h"
#include <unistd.h>

/**
 * print_char - prints a character
 * @args: variable arguments list
 *
 * Return: 1
 */
int print_char(va_list args)
{
	char ch = va_arg(args, int); /* Store the character argument */
					/*frm the variable args list */

	write(1, &ch, 1); /* Write the character to the output */
	return (1); /* Return 1 as the number of characters printed */
}
