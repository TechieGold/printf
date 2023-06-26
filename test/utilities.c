#include "main.h"

/**
 * _strlen - finds the length of a string
 * @s: pointer to string to find length
 *
 * Return: int
 */

int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * _putchar - prints a char
 * @c: the char
 *
 * Return: int
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
