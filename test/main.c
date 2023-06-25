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

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("%% %%\n");

	_printf("Fake printf: %d \nOriginal printf %i\n", len, len2);
	return (0);
}
