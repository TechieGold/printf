#include "main.h"

/**
 * print_long_num - prints an integer usign long datatype
 * @num: the number to print
 * @count: the number of characters printed
 *
 * Return: void
 */

void print_long_num(long int num, int *count)
{
	long int abs;

	if (num < 0)
	{
		*count += _putchar('-');
		abs = (num * -1);
	}
	else
		abs = num;
	printout_long_num(abs, count);
}

/**
 * print_long_num - prints a long number
 * @n: the number
 * @count: the number of char printed
 *
 * Return: void
 */

void printout_long_num(long int n, int *count)
{
	if (n / 10)
		printout_long_num(n / 10, count);
	*count += _putchar((n % 10) + '0');
}

/**
 * print_unsignedlong_int - prints an unsigned long int
 * @num: the number to print
 * @count: the number of characters printed
 *
 * Return: void
 */

void print_unsignedlong_int(unsigned long int num, int *count)
{
	if (num / 10)
		print_unsignedlong_int(num / 10, count);
	*count += _putchar((num % 10) + '0');
}

/**
 * octal_print_long - prints an octal using long
 * @num: the number to print
 * @count: the number of characters printed
 *
 * Return: void
 */

void octal_print_long(unsigned int long num, int *count)
{
	if (num == 0)
		return;
	octal_print(num / 8, count);
	*count += _putchar((num % 8) + '0');
}

/**
 * print_short_num - prints a short num
 * @num: the number to print
 * @count: the number of characters printed
 *
 * Return: void
 */

void print_short_num(short num, int *count)
{
	short abs;

	if (num < 0)
	{
		*count += _putchar('-');
		abs = (num * -1);
	}
	else
		abs = num;
	printout_short_num(abs, count);
}
