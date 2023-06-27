#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define KILO_BYTE 1024
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
	void (*f)(va_list, int *, int *);
} f_select;

int _printf(const char *format, ...);
void format_selector(char c, va_list ap, int *count, int *);
void char_print(va_list, int *, int *);
void string_print(va_list, int *, int *);
void int_print(va_list, int *, int *);
void print_num(unsigned int, int *);
void percent_print(va_list, int *, int *);
int _strlen(char *);
int _putchar(char);
void binary_pr(va_list, int *, int *);
void bin(unsigned int, int *);
void non_print_ascii(va_list, int *, int *);
void unsigned_int(va_list, int *, int *);
void octal(va_list, int *, int *);
void octal_print(unsigned int, int *);
void hexa(va_list, int *, int *);
void hexa_print(unsigned int, int *, int *);
void hexa_cap(va_list, int *, int *);

#endif /* MAIN_H */
