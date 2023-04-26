#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: Pointer to the current position in the format string.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int width = 0;

	while (format[curr_i] != '\0')
	{
		if (is_digit(format[curr_i]))
		{
			width = (width * 10) + (format[curr_i] - '0');
			curr_i++;
		}
		else if (format[curr_i] == '*')
		{
			width = va_arg(list, int);
			curr_i++;
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
