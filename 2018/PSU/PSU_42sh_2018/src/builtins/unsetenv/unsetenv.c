/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** unsetenv
*/

#include "mysh.h"

void pop_all_2(elem_t *elem, char *to_pop, list_t *list)
{
    elem_t *end = list->end;

    while (elem != end) {
        if (my_strncmp(elem->data, to_pop, strlen(to_pop)) == 0) {
            pop_elem_haroun(list, elem);
            return;
        }
        elem = elem->next;
    }
}

void pop_all(list_t *list, char *to_pop)
{
    elem_t *elem = list->start;
    elem_t *end = list->end;
    int size = strlen(to_pop);

    if (my_strncmp(elem->data, to_pop, size) == 0) {
        pop_front_haroun(list);
        return;
    }
    if (my_strncmp(end->data, to_pop, size) == 0) {
        pop_back_haroun(list);
        return;
    }
    elem = elem->next;
    pop_all_2(elem, to_pop, list);
}

void do_unsetenv(list_t *list, char **env_tab)
{
    for (int i = 1; env_tab[i] != NULL; i++)
        pop_all(list, env_tab[i]);
}

int my_unsetenv(main_list_t *main, tree_t *tree, char **input)
{
    (void)tree;

    if (!input || my_tablen(input) < 2) {
        my_printf("unsetenv: Too few arguments.\n");
        return (1);
    } else
        do_unsetenv(&main->env, input);
    return (0);
}
