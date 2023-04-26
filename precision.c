#include "main.h"

/**
* get_precision - Calculates the precision for printing.
* @format: Formatted string in which to print the arguments.
* @index: Pointer to the index of the current character in the format string.
* @args: List of arguments to be printed.
*
* Return: Precision value.
*/
int get_precision(const char *const format, int *const index, va_list args)
{
int currIndex = *index + 1;
int precision = -1;

/* Check if precision is specified in the format string.*/
if (format[currIndex] != '.')
return (precision);

precision = 0;
for (currIndex++; format[currIndex] != '\0'; currIndex++)
{
if (is_digit(format[currIndex]))
{
precision *= 10;
precision += format[currIndex] - '0';
}
else if (format[currIndex] == '*')
{
currIndex++;
precision = va_arg(args, int);
break;
}
else
break;
}

*index = currIndex - 1;
return (precision);
}
