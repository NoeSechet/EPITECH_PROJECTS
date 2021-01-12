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

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; s1[i] && s2[i] && i < n; i += 1)
        if (s1[i] != s2[i])
            return (0);
    return (1);
}

void display_message(void)
{
    clear();
    mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2 - 8,
    "Window too small");
    refresh();
}