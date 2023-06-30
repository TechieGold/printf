#include "main.h"
#include <stdio.h>
#include <limits.h>

/**
 * main - test my _printf
 *
 * Return: Always 0.
 */

int main(void)
{
	int len;
	int len2;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("%% %%\n");
	addr = (void *)0x7ffe637541f0;

	_printf("___");
	_printf("%b\n", 98);
	_printf("%b\n", 0);
	_printf("\n%u\n%o\n%x\n%X\n", 59, 59, 59, 59);
	_printf("%S\n", "Best\nSchool");
	_printf("Fake printf: %d \nOriginal printf %i\n", len, len2);
	_printf("%x \n%X \n%o\n", 0, 0, 0);
	_printf("%b \n%b\n", -1024, 1024);
	_printf("_____________________");
	printf("Address:[%p]\n", addr);
	_printf("Address:[%p]\n", addr);
	_printf("%+d\n%+d\n", 98, -98);
	_printf("%#o %#x %#X %+d\n", 98, 98, 98, 98);
	_printf("% i + % i = % i\n", 98, 98, (98 + 98));
	_printf("% +i + %+ i = % +d\n", -98, 98, (-98 + 98));

	len2 = printf("% ");
	len = _printf("% % % % ");
	_printf("%ld \n%ld\n", 1024L, -1024L);

	printf("_____\n");
	printf("%ld\n", LONG_MAX);
	printf("____\n");
	_printf("%ld", LONG_MAX);
	printf("\n____\n");
	printf("%d %d\n", len, len2);
	return (0);
}
