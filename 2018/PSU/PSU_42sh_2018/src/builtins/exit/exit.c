/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** exit
*/

#include "mysh.h"

int my_exit(main_list_t *main, tree_t *tree, char **input)
{
    (void)main;
    (void)tree;
    int ret_value = 0;

    my_printf("exit\n");
    (input[1]) ? (ret_value = atoi(input[1])) : (ret_value = 0);
    exit((unsigned int)ret_value % 256);
    return (0);
}
