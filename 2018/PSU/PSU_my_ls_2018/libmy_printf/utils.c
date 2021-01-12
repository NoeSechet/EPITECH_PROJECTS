/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils
*/

#include <unistd.h>
#include "utils.h"

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

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0')
        a = a + 1;
    return (a);
}

int show_invis_char(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (!(str[i] <= '~' && str[i] >= ' ')) {
            my_putchar('\\');
            my_put_nbr_base(str[i], "01234567");
        } else {
            my_putchar(str[i]);
        }
    i += 1;
    }
    return (0);
}