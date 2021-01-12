/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_env
*/

#include "mysh.h"

int my_env(main_list_t *main, tree_t *tree, char **input)
{
    (void)input;
    (void)tree;

    for (elem_t *elem = main->env.start; elem != NULL; elem = elem->next)
        my_printf("%s\n", elem->data);
    return (0);
}
