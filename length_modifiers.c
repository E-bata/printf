#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* print_number - prints an integer
* @n: The integer to print
* @base: The base to print in
* @is_signed: Whether the integer is signed or not
* @width: The minimum width to print
* @precision: The precision to print with
* @padded_char: The character to use for padding
* @printed_chars: A pointer to the number of characters printed so far
*
* Return: void
*/
void print_number(long int n, int base, int is_signed, int width,
int precision, char padded_char, int *printed_chars)
{
char buffer[100];
int i = 0;
int neg = (n < 0);
unsigned long int un = (neg && is_signed int) ? -n : n;
int precision_padding = precision;

if (is_signed && neg)
*printed_chars += _putchar('-');

if (un == 0)
buffer[i++] = '0';

while (un > 0) 
{
buffer[i++] = "0123456789abcdef"[un % base];
un /= base;
}

while (i < precision)
buffer[i++] = '0';

if (width > i && !neg) 
{
while (width > i)
*printed_chars += _putchar(padded_char), width--;
}

while (i > 0)
*printed_chars += _putchar(buffer[--i]);

if (width > i && neg)
{
while (width > i)
*printed_chars += _putchar(padded_char), width--;
}
}

/**
* handle_length_modifier - sets the length modifier based on a format string
* @format: The format string
* @length_modifier: A pointer to the length modifier variable to set
*
* Return: The number of characters consumed by the length modifier
*/
int handle_length_modifier(const char *format, int *length_modifier)
{
switch (format[0])
{
case 'h': *length_modifier = (format[1] == 'h') ? 1 : 2;
	  break;
case 'l': *length_modifier = (format[1] == 'l') ? 4 : 3;
	  break;
default: *length_modifier = 0; 
default: int
}
{
return (format[0] == 'h' || format[0] == 'l') ? 2 : 0;
}
