#include "main.h"

/**
 * _printf - prints a formatted string
 * @format: the string
 *
 * Return: int (number of chars printed)
 */

int _printf(const char *format, ...)
{
	int count = 0, i = 0, flag = 0;
	va_list ap;

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
			format_selector(format[i], ap, &count, &flag);
			if (flag == -1)
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
 *
 * Return: void
 */

void format_selector(char c, va_list ap, int *count, int *flag)
{
	f_select f_s[] = {
		{'c', char_print}, {'s', string_print},
		{'%', percent_print}, {'d', int_print},
		{'i', int_print}, {'b', binary_pr},
		{'S', non_print_ascii}, {'u', unsigned_int},
		{'o', octal}, {'x', hexa}, {'X', hexa_cap},
		{'\0', NULL}
	};
	int i;

	i = 0;
	while (f_s[i].s != '\0')
	{
		if (f_s[i].s == c)
		{
			f_s[i].f(ap, count, flag);
			return;
		}
		i++;
	}
	*count += _putchar('%') + _putchar(c);
}
