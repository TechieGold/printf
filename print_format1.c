#include "main.h"

/**
 * char_print - print the char value
 * @ap: ap to print
 * @count: number of values to print
 * @flag: error checker
 * @flag1: flag checker
 * Return: void
 */

void char_print(va_list ap, int *count, __attribute__((unused)) int *flag,
		__attribute__((unused)) int *flag1)
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
 * @flag1: flag checker
 * Return: void
 */

void string_print(va_list ap, int *count, __attribute__((unused)) int *flag,
		__attribute__((unused)) int *flag1)
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
 * @flag1: flag checker
 * Return: void
 */

void int_print(va_list ap, int *count, int *flag, int *flag1)
{
	int num;
	unsigned int abs = 0;

	num = va_arg(ap, int);
	if (num >= 0 && (*flag == '+' || (*flag == 32 && *flag1 == '+')))
		*count += _putchar('+');
	if (num >= 0 && (*flag == 32 && *flag1 != '+'))
		*count += _putchar(' ');
	if (*flag == 'l')
	{
		print_long_num((long int)num, count);
		return;
	}
	if (*flag == 'h')
	{
		print_short_num((short)num, count);
		return;
	}
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
 * @flag1: flag checker
 * Return: void
 */

void percent_print(__attribute__((unused)) va_list ap, int *count,
		__attribute__((unused)) int *flag,
		__attribute__((unused)) int *flag1)
{
	*count += _putchar('%');
}
