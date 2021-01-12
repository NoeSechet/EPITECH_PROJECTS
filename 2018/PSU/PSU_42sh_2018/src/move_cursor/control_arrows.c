/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** control_arrows
*/

#include "mysh.h"

void add_character_str(char c, term_t *all)
{
    char *add = malloc(sizeof(char) * 2);

    all->pos += 1;
    add[0] = c;
    add[1] = '\0';
    all->str = add_changes(all->str, add, all->pos);
    free(add);
}

char *delete_character_str(char *str, term_t *all)
{
    int nb = 0;
    int c = 0;
    char *new = malloc(sizeof(char) * (strlen(str)));

    for (; str[nb]; nb++)
        if (nb + 1 != all->pos) {
            new[c] = str[nb];
            c++;
        }
    free(str);
    new[nb - 1] = '\0';
    return (new);
}

void remove_character(term_t *all)
{
    int nb = 0;
    if (all->pos >= 1) {
        all->str = delete_character_str(all->str, all);
        nb = my_strlen(all->str) - all->pos + 1;
        for (int c = 0; c != nb; c++)
            my_printf("%c%c%c", 27, 91, 67);
        my_printf("\b");
        my_printf(" ");
        my_printf("\b");
        for (int c = 0; c != nb; c++)
            my_printf("%c%c%c", 27, 91, 68);
        all->pos -= 1;
    }
}

void arrow_control(term_t *all, list_t *history, int *index)
{
    (void)index;
    (void)history;
    char d = getchar();
    char t = getchar();

    if (d == 91 && t == 68 && all->pos > 0) {
        all->pos -= 1;
        my_printf("%c%c%c", 27, 91, 68);
        return;
    }
    if (d == 91 && t == 67 && all->pos < my_strlen(all->str)) {
        all->pos += 1;
        my_printf("%c%c%c", 27, 91, 67);
        return;
    }
}
