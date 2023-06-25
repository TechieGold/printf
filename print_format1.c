#include "main.h"

/**
 * char_print - print the char value
 * @ap: ap to print
 * @count: number fo values to print
 *
 * Return: void
 */

void char_print(va_list ap, int *count)
{
	unsigned char c;

	c = va_arg(ap, int);
	*count += write(1, &c, 1);
}

/**
 * string_print - prints a string
 * @ap: variable arg
 * @count: the number of values to print
 *
 * Return: vooid
 */

void string_print(va_list ap, int *count)
{
	char *string;
	int len;

	string = va_arg(ap, char *);
	len = _strlen(string);

	if (string == NULL)
	{
		len = _strlen("(nil)");
		*count += write(1, "(nil)", len);
		return;
	}
	*count += write(1, string, len);
}

/**
 * percent_print - prints the percent
 * @ap: the variable arg
 * @count: number of value printed
 *
 * Return: void
 */

void percent_print(__attribute__((unused)) va_list ap, int *count)
{
	char c = '%';
	*count += write(1, &c, 1);
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
	char num;

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
	char c;

	if (n < 0)
	{
		char c;

		c = '-';
		n = (-n);
		*count += write(1, &c, 1);
	}

	if (n / 10)
	{
		print_num(n / 10, count);
	}

	c = (n % 10) + '0';
	*count += write(1, &c, 1);
}
