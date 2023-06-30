#include "main.h"

/**
 * _printf - prints a formatted string
 * @format: the string
 *
 * Return: int (number of chars printed)
 */

int _printf(const char *format, ...)
{
	int count = 0, i = 0, flag = 0, flag1 = 0;
	va_list ap;
	int error = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			error = flag_character(format, &i, ap, &count,
					&flag, &flag1);
			if (error != 0)
				return (-1);
		}
		else
			count += _putchar(format[i]);
		i++;
	}

	va_end(ap);
	return (count);
}

/**
 * format_selector - selects the function to execute
 * @c: char value to check
 * @ap: the variadic argument
 * @count: the number of values to print
 * @flag: error checker
 * @flag: the second flag checker
 *
 * Return: void
 */

void format_selector(char c, va_list ap, int *count, int *flag,
		int *flag1)
{
	f_select f_s[] = {
		{'c', char_print}, {'s', string_print},
		{'%', percent_print}, {'d', int_print},
		{'i', int_print}, {'b', binary_pr},
		{'S', non_print_ascii}, {'u', unsigned_int},
		{'o', octal}, {'x', hexa}, {'X', hexa_cap},
		{'p', pointer_addr}, {'\0', NULL}
	};
	int i;

	i = 0;
	while (f_s[i].s != '\0')
	{
		if (f_s[i].s == c)
		{
			f_s[i].f(ap, count, flag, flag1);
			return;
		}
		i++;
	}
	*count += _putchar('%') + _putchar(c);
}

/**
 * flag_character - checks for flags
 * @format: the string
 * @i: the index to start from
 * @ap: the variadic function
 * @count: the number of characters to print
 * @flag: the type of flag char 1
 * @flag1: the type of flag char 2
 *
 * Return: if error, return -1
 */

int flag_character(const char *format, int *i, va_list ap, int *count,
		int *flag, int *flag1)
{
	int index = *i;

	if (format[index] == '+')
	{
		*flag = '+';
		index++;
		if (format[index] == 32)
		{
			*flag1 = 32;
			index++;
		}
	}
	else if (format[index] == '#')
	{
		*flag = '#';
		index++;
	}
	else if (format[index] == 32)
	{
		*flag = 32;
		index++;
		if (format[index] == '+')
		{
			*flag = '+';
			index++;
		}
		else if (format[index] == '\0')
			return (-1);
	}
	*i = index;
	format_selector(format[index], ap, count, flag, flag1);
	return (0);
}
