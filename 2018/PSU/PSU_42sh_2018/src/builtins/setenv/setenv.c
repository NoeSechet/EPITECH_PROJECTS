/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** [enter description here]
*/

#include "mysh.h"

int do_setenv(list_t *list, char **input)
{
    char *name = input[1];
    char *value = (!input[2]) ? (value = "") : (value = input[2]);

    if (check_first(name) == 0)
        return (do_setenv_2(list, name, value));
    else
        return (1);
}

int my_setenv(main_list_t *main, tree_t *tree, char **input)
{
    if (!input[1])
        return (my_env(main, tree, input));
    else if (my_tablen(input) > 3) {
        my_printf("setenv: Too many arguments.\n");
        return (1);
    } else
        return (do_setenv(&main->env, input));
}
