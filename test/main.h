#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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
	void (*f)(va_list, int *count);
} f_select;

int _printf(const char *format, ...);
int format_selector(char, va_list, int *);
void char_print(va_list, int *);
void string_print(va_list, int *);
void int_print(va_list, int *);
void percent_print(va_list, int *);
void print_num(int, int *);
int _strlen(char *s);
int _putchar(char);
#endif /* MAIN_H */
