#include "main.h"
#include <stdio.h>

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

	num = va_arg(ap, int);
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
