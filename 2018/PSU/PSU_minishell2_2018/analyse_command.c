/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** analyse_command.c
*/

#include "utils_mini2.h"
#include "mini_command.h"
#include "bin_tree.h"

static const minishell_t minilist[] = {
    {"cd", 2, &com_cd},
    {"setenv", 6, &com_setenv},
    {"unsetenv", 8, &com_unsetenv},
    {"env", 3, &com_env},
    {"./", 2, &com_exec},
    {"exit", 4, &com_exit},
    {0, 0, NULL}
};

int analyse_command(bin_tree_t *bin_tree, list_t *list)
{
    char **tab = my_str_to_word_array(bin_tree->command_parser);
    char *path = NULL;

    for (int i = 0; minilist[i].command != 0; i += 1)
        if (comp_word_pre(tab[0], minilist[i].command,
        minilist[i].length) == 1) {
            minilist[i].funcPointer(tab, list, bin_tree);
            return (1);
        }
    if ((path = check_com_exist(tab, list, bin_tree)) != NULL) {
        execute_binary(tab, path, list, bin_tree);
    }
    return (0);
}