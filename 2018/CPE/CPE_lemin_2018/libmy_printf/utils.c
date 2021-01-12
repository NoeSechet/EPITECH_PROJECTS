/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils
*/

#include "utils_printf.h"

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_strlen(char const *str)
{
    int len = 0;

    for (; str[len] != '\0'; len += 1);
    return (len);
}

int my_putstr(char const *str)
{
    if (str != NULL)
        write(1, str, my_strlen(str));
    else
        return (-1);
    return (0);
}

int show_invis_char(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (!(str[i] <= '~' && str[i] >= ' ')) {
            my_putchar('\\');
            my_put_nbr_base(str[i], "01234567");
        } else
            my_putchar(str[i]);
    }
    return (0);
}