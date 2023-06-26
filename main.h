#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct formatSelector - struct for format type
 * @s: specifier to execute
 * @f: function pointer
 *
 * Description: used to store the functions to execute
 */

typedef struct formatSelector
{
	char s;
	void (*f)(va_list, int *);
} f_select;

int _printf(const char *format, ...);
void format_selector(char c, va_list ap, int *count);
void char_print(va_list, int *);
void string_print(va_list, int *);
void int_print(va_list, int *);
void print_num(unsigned int, int *);
void percent_print(va_list, int *);
int _strlen(char *);
int _putchar(char);

#endif /* MAIN_H */
