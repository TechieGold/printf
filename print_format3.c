#include "main.h"

/**
 * octal_print - prints an octal value
 * @num: the value to convert
 * @count: the number of variables printed
 *
 * Return: void
 */

void octal_print(unsigned int num, int *count)
{
	if (num == 0)
		return;
	octal_print(num / 8, count);
	*count += _putchar((num % 8) + '0');
}

/**
 * hexa - converts an int to hexadecimal
 * @ap: the variadic args
 * @count: the number of args passed
 * @flag: error checker
 *
 * Return: void
 */

void hexa(va_list ap, int *count,
		__attribute__((unused)) int *flag)
{
	unsigned int num;
	int *cap, lowercase = 0;

	cap = &lowercase;
	num = va_arg(ap, unsigned int);
	hexa_print(num, count, cap);
}

/**
 * hexa_print - prints an hexadecimal
 * @num: the num to convert
 * @count: the number of characters printe
 * @cap: check to print in upper or lower
 *
 * Return: void
 */

void hexa_print(unsigned int num, int *count, int *cap)
{
	if (num == 0)
		return;
	hexa_print(num / 16, count, cap);
	if ((num % 16) > 9)
	{
		int value[6] = {10, 11, 12, 13, 14, 15};
		char upper_chr[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
		char low_chr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
		int i = 0, decimal = num % 16;

		if (*cap == 1)
		{
			while (i++ < 6)
				if (value[i] == decimal)
					*count += _putchar(upper_chr[i]);
		}
		else
		{
			while (i++ < 6)
				if (value[i] == decimal)
					*count += _putchar(low_chr[i]);
		}
	}
	else
		*count += _putchar((num % 16) + '0');
}

/**
 * hexa_cap - prints a hexadecimal in uppercase
 * @ap: the va_list arg
 * @count: the number of args printed
 * @flag: error checker
 *
 * Return: void
 */

void hexa_cap(va_list ap, int *count,
		__attribute__((unused)) int *flag)
{
	unsigned int num;
	int *cap, upper = 1;

	cap = &upper;
	num = va_arg(ap, unsigned int);
	hexa_print(num, count, cap);
}

