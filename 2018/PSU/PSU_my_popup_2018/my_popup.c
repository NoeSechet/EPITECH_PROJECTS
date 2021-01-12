/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include <ncurses.h>

int my_strlen(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len += 1;
    return (len);
}

int main(int ac, char **av)
{
    (void)ac;
    initscr();
    char *str = av[1];

    for (;;) {
        clear();
        move((LINES/2), ((COLS/2) - my_strlen(str)/2));
        printw(str);
        if (getch() == ' ')
            break;
    }
    refresh();
    endwin();
    return (0);
}