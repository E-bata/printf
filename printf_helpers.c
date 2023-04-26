#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_number - prints an integer
 * @n: The integer to print
 * @is_signed: Whether the integer is signed or not
 * @precision: The precision to print with
 * @padding: The padding character to use
 * @base: The base to print in
 * @printed_chars: A pointer to the number of characters printed so far
 *
 * Return: void
 */
void print_number(long int n, int is_signed, int precision, char padding,
		  int base, int *printed_chars)
{
	int digits = 0, divisor = 1;
	long int n_copy = n;

	if (n < 0)
	{
		*printed_chars += _putchar('-');
		n = -n;
	}
	else if (is_signed int)
	{
		*printed_chars += _putchar('+');
	}

	while (n_copy != 0)
	{
		digits++;
		divisor *= base;
		n_copy /= base;
	}

	divisor /= base;

	while (digits < precision)
	{
		*printed_chars += _putchar(padding);
		digits++;
	}

	while (divisor != 0)
	{
		*printed_chars += _putchar(n / divisor % base + '0');
		divisor /= base;
	}
}

/**
 * handle_flags - handles the flags in a format specifier
 * @format: The format specifier
 * @flags: The flag variables to set
 *
 * Return: The number of characters consumed by the flags
 */
int handle_flags(const char *format, struct flags *flags)
{
	int consumed_chars = 0;

	while (1)
	{
		switch (format[consumed_chars])
		{
		case '+':
			flags->is_signed int = 1;
			consumed_chars++;
			break;
		case ' ':
			if (!flags->is_signed int)
			{
				_putchar(' ');
				flags->printed_chars++;
			}
			consumed_chars++;
			break;
		case '#':
			flags->padding = '0';
			consumed_chars++;
			break;
		default:
			return (consumed_chars);
		}
	}
}

/**
 * print_format - prints a format specifier
 * @format: The format specifier
 * @arg_list: The argument list
 * @flags: The flags to use
 *
 * Return: void
 */
void print_format(const char *format, va_list arg_list, struct flags flags)
{
	switch (*format)
	{
	case 'd':
	case 'i':
	case 'u':
	{
		long int n;

		if (flags.length == 2)
			n = (short)va_arg(arg_list, int);
		else if (flags.length == 3)
			n = va_arg(arg_list, long);
		else
			n = va_arg(arg_list, int);

		if (*format == 'd' || *format == 'i')
			flags.is_signed int = (n < 0);

		if (*format == 'u')
			flags.is_signed int = 0;

		if (flags.precision == -1)
			flags.precision = 1;

		print_number(n, flags.is_signed int, flags.precision, flags.padding,
			     10, &flags.printed_chars);
	}
