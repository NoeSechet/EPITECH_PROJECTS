/*
** EPITECH PROJECT, 2018
** disp_stdarg.c
** File description:
** disp_stdarg
*/

#include <stdarg.h>

int disp_stdarg(char *s, ...)
{
	va_list args;
	va_start(args, s);
	for (int type = 0; s[type] != '\0'; type += 1) {
		if (s[type] == 'c') {
			my_putchar(va_arg(args, int));
			my_putchar('\n');
		}

		if (s[type] == 'i') {
			my_put_nbr(va_arg(args, int));
			my_putchar('\n');
		}
		if (s[type] == 's') {
			my_putstr(va_arg(args, char *));
			my_putchar('\n');
		}
	}
	va_end(args);
	return (0);
}