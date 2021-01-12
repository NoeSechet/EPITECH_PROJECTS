/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** move_cursor
*/

#include "mysh.h"

void display_term(char *str, int pos, char *pwd)
{
    char *changes = my_strdup(" $ \0");

    changes = add_changes(pwd, changes, strlen(pwd) + 1);
    changes = add_changes(changes, str, strlen(changes) + 1);
    for (int nb = strlen(changes); nb != 0; nb--)
        my_printf("%c%c%c", 27, 91, 68);
    my_printf("%s", changes);
    for (int nb = strlen(str) + 4; nb != 0; nb--)
        my_printf("%c%c%c", 27, 91, 68);
    for (int nb = pos + 4; nb != 0; nb--)
        my_printf("%c%c%c", 27, 91, 67);
    free(changes);
}

int switch_tab(char c, term_t *all, list_t *history, int *index)
{
    switch (c) {
        case 27:
            arrow_control(all, history, index);
            return (0);
        case 0x7f:
            remove_character(all);
            return (0);
        case 10:
            return (1);
        case 4:
            all->str = NULL;
            all->ver = 1;
            return (1);
        default:
            add_character_str(c, all);
            return (0);
    }
}

void check_user_input(term_t *all, list_t *history)
{
    char c;
    int index = 0;

    tcgetattr(0, &all->old);
    all->new = all->old;
    all->new.c_lflag &= ~ICANON;
    all->new.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &all->new);
    fflush(stdout);
    while (1) {
        c = getchar();
        if (switch_tab(c, all, history, &index) == 1)
            break;
        display_term(all->str, all->pos, all->prompt);
    }
    tcsetattr(0, TCSANOW, &all->old);
}

void init_term(term_t *all, char *prompt)
{
    all->str = malloc(sizeof(char) * 1);
    all->str[0] = '\0';
    all->prompt = prompt;
    all->pos = 0;
    all->ver = 0;
}

char *new_gnl(term_t *all, char *prompt, list_t *history)
{
    init_term(all, prompt);
    check_user_input(all, history);
    my_printf("\n");
    return (all->str);
}
