#include "main.h"

/**
 * char_print - print the char value
 * @ap: ap to print
 * @count: number of values to print
 *
 * Return: void
 */

void char_print(va_list ap, int *count)
{
	unsigned char c;

	c = va_arg(ap, int);
	*count += _putchar(c);
}

/**
 * string_print - prints a string
 * @ap: variadic arg
 * @count: the number of values to print
 *
 * Return: void
 */

void string_print(va_list ap, int *count)
{
	char *string;
	int len;

	string = va_arg(ap, char *);
	if (string == NULL)
		*count += write(1, "(nil)", 5);
	else
	{
		len = _strlen(string);
		*count += write(1, string, len);
	}
}

/**
 * int_print - prints an int
 * @ap: the variadic arg
 * @count: the number of args printed
 *
 * Return: void
 */

void int_print(va_list ap, int *count)
{
	int num;

	num = va_arg(ap, int);
	print_num(num, count);
}

/**
 * print_num - prints a number
 * @n: the number
 * @count: the number of args printed
 *
 * Return: void
 */

void print_num(int n, int *count)
{
	if (n < 0)
	{
		*count += _putchar('-');
		n = (-n);
	}

	if (n / 10)
		print_num(n / 10, count);
	*count += _putchar((n % 10) + '0');
}

/**
 * percent_print - prints a percentage
 * @ap: the variadic args
 * @count: the number of chars printed
 *
 * Return: void
 */

void percent_print(__attribute__((unused)) va_list ap, int *count)
{
	*count += _putchar('%');
}
