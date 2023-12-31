#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

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
	void (*f)(va_list, int *, int *, int *);
} f_select;

int _printf(const char *format, ...);
int flag_character(const char *, int *, va_list, int *, int *, int *);
void format_selector(char, va_list, int *, int *, int *);
void char_print(va_list, int *, int *, int *);
void string_print(va_list, int *, int *, int *);
void int_print(va_list, int *, int *, int *);
void print_num(unsigned int, int *);
void percent_print(va_list, int *, int *, int *);
int _strlen(char *);
int _putchar(char);
void binary_pr(va_list, int *, int *, int *);
void bin(unsigned int, int *);
void non_print_ascii(va_list, int *, int *, int *);
void unsigned_int(va_list, int *, int *, int *);
void octal(va_list, int *, int *, int *);
void octal_print(unsigned int, int *);
void hexa(va_list, int *, int *, int *);
void hexa_print(unsigned long int, int *, int *);
void hexa_cap(va_list, int *, int *, int *);
void pointer_addr(va_list, int *, int *, int *);
void print_long_num(long int, int *);
void printout_long_num(unsigned long int, int *);
void print_unsignedlong_int(unsigned long int, int *);
void octal_print_long(unsigned int long, int *);
void print_short_num(short, int *);
void printout_short_num(short, int *);
void print_unsignedshort_int(unsigned short, int *);
void octal_print_short(unsigned short, int *);
void hexa_print_short(unsigned short, int *, int *);
#endif /* MAIN_H */
