#include "main.h"

/**
 * handle_minus_flag - Handles the '-' flag character for non-custom conversion
 *                     specifiers.
 * @flags: Pointer to the flags variable.
 * @format: Formatted string in which to print the arguments.
 * @i: Pointer to the current position in the format string.
 *
 * Return: void.
 */
void handle_minus_flag(int *flags, const char *format, int *i)
{
	int curr_i = *i;

	*flags |= FLAG_MINUS;

	curr_i++;

	/* Skip all digits and '*' in the field width */
	while (is_digit(format[curr_i]) || format[curr_i] == '*')
		curr_i++;

	*i = curr_i - 1;
}
