#include "main.h"

/**
 * _printf - prints a formated string
 * @format: the string
 *
 * Return: int
 */

int _printf(const char *format, ...)
{
	int count = 0, i = 0;
	va_list ap;
	int flag;

	va_start(ap, format);
	while ((format != NULL) && (format[i]))
	{
		if (format[i] == '%')
		{
			i++;
			flag = format_selector(format[i], ap, &count);
			if (flag == -1)
				exit(EXIT_FAILURE);
		}
		else if (format[i] != '%')
		{
			count += _putchar(format[i]);
		}
		i++;
	}

	va_end(ap);
	return (count);
}

/**
 * format_selector - selects the function to execute
 * @c: char value to check
 * @ap: the va argument
 * @count: number of values to print
 *
 * Return: void
 */

int format_selector(char c, va_list ap, int *count)
{
	f_select f_s[] = {
		{'c', char_print},
		{'s', string_print},
		{'%', percent_print},
		{'d', int_print},
		{'i', int_print},
		{'\0', NULL}
	};
	int i;

	if (!c || !ap || count == NULL)
		return (-1);
	i = 0;
	while (f_s[i].s != '\0')
	{
		if (f_s[i].s == c)
		{
			f_s[i].f(ap, count);
			return (0);
		}
		i++;
	}
	return (-1);
}