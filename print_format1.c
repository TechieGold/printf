#include "main.h"

/**
 * char_print - print the char value
 * @ap: ap to print
 * @count: number of values to print
 * @flag: error checker
 * Return: void
 */

void char_print(va_list ap, int *count, __attribute__((unused)) int *flag)
{
	unsigned char c;

	c = va_arg(ap, int);
	*count += _putchar(c);
}

/**
 * string_print - prints a string
 * @ap: variadic arg
 * @count: the number of values to print
 * @flag: error checker
 * Return: void
 */

void string_print(va_list ap, int *count, __attribute__((unused)) int *flag)
{
	char *string;
	int len;

	string = va_arg(ap, char *);
	if (string == NULL)
		string = "(null)";
	len = 0;
	while (string[len])
	{
		*count += _putchar(string[len]);
		len++;
	}
}

/**
 * int_print - prints an int
 * @ap: the variadic arg
 * @count: the number of args printed
 * @flag: error checker
 * Return: void
 */

void int_print(va_list ap, int *count, __attribute__((unused)) int *flag)
{
	int num;
	unsigned int abs = 0;

	num = va_arg(ap, int);
	if (num < 0)
	{
		*count += _putchar('-');
		abs = (num * -1);
	}
	else
		abs = num;
	print_num(abs, count);
}

/**
 * print_num - prints a number
 * @n: the number
 * @count: the number of args printed
 *
 * Return: void
 */

void print_num(unsigned int n, int *count)
{
	if (n / 10)
		print_num(n / 10, count);
	*count += _putchar((n % 10) + '0');
}

/**
 * percent_print - prints a percentage
 * @ap: the variadic args
 * @count: the number of chars printed
 * @flag: error checker
 * Return: void
 */

void percent_print(__attribute__((unused)) va_list ap, int *count,
		__attribute__((unused)) int *flag)
{
	*count += _putchar('%');
}
