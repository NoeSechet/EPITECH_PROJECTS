/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** utils.c
*/

#include "utils.h"

void my_putchar(char c)
{
    write (1, &c, 1);
}

void my_putstr(char *str)
{
    int a = 0;
    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
}
