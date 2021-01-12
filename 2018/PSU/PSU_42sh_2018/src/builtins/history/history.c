/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** history
*/

#include "mysh.h"

void stock_history(list_t *history, char *str)
{
    if (str)
        push_back_haroun(history, str);
}

int my_history(main_list_t *main, tree_t *tree, char **input)
{
    (void)tree;
    elem_t *elem = main->history.start;
    int i = 1;

    while (elem != NULL) {
        my_printf("%i %s\n", i, elem->data);
        elem = elem->next;
        i++;
    }
    (void)input;
    return (0);
}
