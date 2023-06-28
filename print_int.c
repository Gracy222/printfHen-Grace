#include "main.h"
#include <unistd.h> /* Include the necessary header for the write function */

/**
 * print_integer - prints an integer value
 * @args: variable arguments list
 * Return: the total number of digits printed
 */
int print_integer(va_list args)
{
	int number = va_arg(args, int); /** Retrieve the integer argument */

	int digit_count = 0; /* Initialize the digit count to 0 */

	char digit_char; /* Variable to hold the character rep of the digit */

	if (number < 0)
	{
		write(1, "-", 1); /* Print a negative sign if the number is negative */
		number *= -1; /* Make the number positive */

		digit_count++; /* Increment the digit count to account for the -ve sign */
	}

	if (number == 0)
	{
		write(1, "0", 1); /* Print a single '0' digit if the number is zero */
		digit_count++; /* Increment the digit count to account for the '0' digit */
	}

	while (number > 0)
	{
		int digit = number % 10; /* Extract the rightmost digit of the number */

		digit_char = '0' + digit; /* Cal the char rep of the digit */

		write(1, &digit_char, 1); /* Print the digit character */
		number /= 10; /* Remove the rightmost digit from the number */
		digit_count++; /* Increment the digit count */
	}

	return (digit_count); /* Return the total number of digits printed */
}
