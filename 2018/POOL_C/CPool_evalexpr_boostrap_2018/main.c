/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "utils.h"
#include <stdio.h>

int parse_val(char **);
int unm(char **);

/*char *mstrdup(char const *str)
{
	int len = 0;
	while (str[len++]);

	char *new_str = malloc(sizeof(char) * len);
	new_str[len - 1] = '\0';
	for (int i = 0 ; i < len - 1 ; i++)
		new_str[i] = str[i];
	return (new_str);
}*/

void read_space(char **str)
{
	char c = readc(str);
	while (c == ' ')
		c = readc(str);
	*str = *str - 1;
}

int factors(char **str)
{
	int a = unm(str);
	char op = '+';

	read_space(str);
	op = readc(str);
	
	if (op == '*') {
		read_space(str);
		a = a * unm(str);
	}
	if (op == '/') {
		read_space(str);
		a = a / unm(str);
	}
	if (op == '%') {
		read_space(str);
		a = a % unm(str);
	}
	*str = *str - 1;
	return (a);
}

int summands(char **str)
{
	int a = factors(str);
	char op = '+';

	read_space(str);
	while (op != '\0' && op != ')') {
		op = readc(str);
		read_space(str);
		if (op == '+')
			a = a + factors(str);
		if (op == '-')
			a = a - factors(str);
		if (op == '*')
			a = a * factors(str);
		if (op == '/')
			a = a / factors(str);
		if (op == '%')
			a = a % factors(str);
	}
	return (a);
}

int parse_val(char **str)
{
	char c = readc(str);

	if(c == '(')
		return (summands(str));
	*str = *str - 1;
	return (number(str));
}

int unm(char **str)
{
	if ((*str)[0] == '-') {
		readc(str);
		return (-unm(str));
	}
	return (parse_val(str));
}

int main(int ac, char **av)
{
	(void)ac;

	my_put_nbr(summands(&av[1]));
	return(0);
}