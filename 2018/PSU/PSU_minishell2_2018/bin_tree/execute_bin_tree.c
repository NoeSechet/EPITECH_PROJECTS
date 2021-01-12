/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** execute_bin_tree.c
*/

#include "utils_mini2.h"
#include "mini_command.h"
#include "bin_tree.h"

static const tree_operator_t operator[] = {
    {";", &semi_col_exec},
    {">>", &d_redic_right_exec},
    {"<<", &d_redic_left_exec},
    {">", &redic_right_exec},
    {"<", &redic_left_exec},
    {"|", &pipe_exec},
    {NULL, NULL}
};

int execute_bin_tree(bin_tree_t *bin_tree, list_t *list)
{
    for (int i = 0; operator[i].op != NULL; i += 1) {
        if (comp_word(bin_tree->command_parser, operator[i].op,
        my_strlen(operator[i].op)) == 1) {
            return (operator[i].functPointer(bin_tree, list));
        }
    }
    analyse_command(bin_tree, list);
    return (1);
}