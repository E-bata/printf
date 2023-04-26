#include "main.h"

/**
* get_field_width - Calculates the field width for printing
* @format: Formatted string in which to print the arguments.
* @i: Pointer to the current position in the format string.
* @list: List of arguments to be printed.
*
* Return: Field width.
*/
int get_field_width(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int field_width = 0;

while (format[curr_i] != '\0')
{
if (is_digit(format[curr_i]))
{
field_width = (field_width * 10) + (format[curr_i] - '0');
curr_i++;
}
else if (format[curr_i] == '*')
{
field_width = va_arg(list, int);
curr_i++;
break;
}
else
{
break;
}
}

*i = curr_i - 1;

return (field_width);
}
