#include "main.h"

/**
 * binary_pr - converts an unsigned int to binary
 * @ap: the variadic args
 * @count: the number of bytes to print
 * @flag: flag to check error
 *
 * Return: void
 */

void binary_pr(va_list ap, int *count, __attribute__((unused)) int *flag)
{
	unsigned int num;
	int n;

	n = va_arg(ap, int);
	if (n < 0)
	{
		*flag = -1;
		return;
	}
	num = (1 * n);
	bin(num, count);
}

/**
 * bin - prints the binary
 * @num: the int to convert
 * @count: the num of args printed
 *
 * Return: void
 */

void bin(unsigned int num, int *count)
{
	if (num == 0)
		return;
	bin(num / 2, count);
	*count += _putchar((num % 2) + '0');
}

/**
 * non_print_ascii - prints a non_printable ascii asn \x
 * @ap: the variadic arg
 * @count: the numbers of characters printed
 * @flag: error checker
 *
 * Return: void
 */

void non_print_ascii(va_list ap, int *count,
		__attribute__((unused)) int *flag)
{
	char *s = va_arg(ap, char *);
	int i = 0;

	if (s == NULL)
		s = "(null)";
	while (s[i])
	{
		if (s[i] < 0 || s[i] < 32 || s[i] >= 127)
		{
			unsigned int num = s[i];
			int cap = 1;

			*count += _putchar('\\') + _putchar('x');
			if (num <= 15)
				*count += _putchar('0');
			hexa_print(num, count, &cap);
		}
		else
			*count += _putchar(s[i]);

		i++;
	}
}

/**
 * unsigned_int - this prints an unsigned int
 * @ap: the variadic amount of args
 * @count: the numbers of characters printed
 * @flag: error checker
 *
 * Return: void
 */

void unsigned_int(va_list ap, int *count,
		__attribute__((unused)) int *flag)
{
	unsigned int num;

	num = va_arg(ap, unsigned int);
	print_num(num, count);
}

/**
 * octal - converts an int to octal
 * @ap: the variadic args
 * @count: the number of args passed
 * @flag: error checker
 *
 * Return: void
 */

void octal(va_list ap, int *count,
		__attribute__((unused)) int *flag)
{
	unsigned int num;

	num = va_arg(ap, unsigned int);
	if (num == 0)
	{
		*count += _putchar('0');
	}
	octal_print(num, count);
}
