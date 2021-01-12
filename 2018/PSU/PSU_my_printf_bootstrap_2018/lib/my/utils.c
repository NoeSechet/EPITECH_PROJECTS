/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils
*/

#include <unistd.h>

void my_putchar(char c)
{
	write (1, &c, 1);
}

int my_putstr(char const *str)  
{
    int a = 0;
    while (str[a] != '\0') {
	my_putchar(str[a]);
	a++;
    }
    return (0);
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

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
    a = a + 1;
    }
    return (a);
}