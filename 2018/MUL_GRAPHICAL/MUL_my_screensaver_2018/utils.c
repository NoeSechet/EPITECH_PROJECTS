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

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; s1[i] && s2[i] && i < n; i += 1)
        if (s1[i] != s2[i])
            return (0);
    return (1);
}

int my_random(int min, int max)
{
    srand(time(NULL));
    return (rand() % (max - min) + min);
}