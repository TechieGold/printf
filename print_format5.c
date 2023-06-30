#include "main.h"

/**
 * printout_short_num - prints a num of short datatype
 * @num: the num
 * @count: the number of characters printed
 *
 * Return: void
 */

void printout_short_num(short num, int *count)
{
	if (num / 10)
		printout_short_num(num / 10, count);
	*count += _putchar((num % 10) + '0');
}

/**
 * print_unsignedshort_int - prints unsigned short
 * @num: the number
 * @count: the number of characters printed
 *
 * Return: void
 */

void print_unsignedshort_int(unsigned short num, int *count)
{
	if (num / 10)
		print_unsignedshort_int(num / 10, count);
	*count += _putchar((num % 10) + '0');
}

/**
 * octal_print_short - prints an octal value
 * @num: the unsigned short passed
 * @count: the number of char to print
 *
 * Return: void
 */

void octal_print_short(unsigned short num, int *count)
{
	if (num == 0)
		return;
	octal_print(num / 8, count);
	*count += _putchar((num % 8) + '0');
}

/**
 * hexa_print_short - prints an hexadecimal
 * @num: the num to convert
 * @count: the number of characters printe
 * @cap: check to print in upper or lower
 *
 * Return: void
 */

void hexa_print_short(unsigned short num, int *count, int *cap)
{
	if (num == 0)
		return;
	hexa_print(num / 16, count, cap);
	if ((num % 16) > 9)
	{
		int value[6] = {10, 11, 12, 13, 14, 15};
		char upper_chr[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
		char low_chr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
		int i = 0;
		unsigned short decimal = num % 16;

		if (*cap == 1)
		{
			while (i < 6)
			{
				if (value[i] == decimal)
					*count += _putchar(upper_chr[i]);
				i++;
			}
		}
		else
		{
			while (i < 6)
			{
				if (value[i] == decimal)
					*count += _putchar(low_chr[i]);
				i++;
			}
		}
	}
	else
		*count += _putchar((num % 16) + '0');
}
