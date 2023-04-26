#include "main.h"

/**
 * handle_zero_flag - Handles the '0' flag character for non-custom conversion
 *                     specifiers.
 * @flags: Pointer to the flags variable.
 * @format: Formatted string in which to print the arguments.
 * @i: Pointer to the current position in the format string.
 *
 * Return: void.
 */

void handle_zero_flag(int *flags, const char *format, int *i)
{
	int curr_i = *i;

	while (format[curr_i] == '0')
	{
		*flags |= FLAG_ZERO;
		curr_i++;
	}

	*i = curr_i - 1;
}
