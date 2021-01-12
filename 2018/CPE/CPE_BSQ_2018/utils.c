/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils
*/

#include "utils.h"

void my_putchar(char c)
{
    write(1, &c, 1);
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

int my_strlen(char *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a += 1;
    }
    return (a);
}

int min(int a, int b)
{
    return (a < b ? a : b);
}

int check_coords(int x, int y, int *lineLength)
{
    return (x + y * (*lineLength));
}