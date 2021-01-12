/*
** EPITECH PROJECT, 2018
** utils
** File description:
** utils
*/

#include <unistd.h>

void my_putchar(char c)
{
	write (1, &c, 1);
}

int power(int v, int p)
{
	int res = 1;

	for (int y = 0 ; y < p ; y++)
		res = res * v;
	return (res);
}

char readc(char **str)
{
	char r = (*str)[0];

	*str = *str + 1;
	return (r);
}

int number(char **str)
{
	int i = 0;
	int res = 0;
	char sign = '+';

	if ((*str)[0] == '-' || (*str)[0] == '+')
		sign = readc(str);
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
		i++;
	for (; i > 0 ; i--)
		res = res + ((readc(str) - '0') * power(10, i - 1));
	return (sign == '-' ? res*-1 : res);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar ('-');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
    return (0);
}