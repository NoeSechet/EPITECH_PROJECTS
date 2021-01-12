/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** complete_tree.c
*/

#include "lib.h"
#include "struct_tree.h"

static const tree_operator_t operator[] = {
    {";"},
    {"||"},
    {"&&"},
    {">>"},
    {"<<"},
    {">"},
    {"<"},
    {"|"},
    {NULL}
};

void str_clean_parentheses(tree_t *bin_tree)
{
    if (bin_tree->command[0] == '(' &&
    bin_tree->command[strlen(bin_tree->command) - 1] == ')') {
        bin_tree->command += 1;
        bin_tree->command[strlen(bin_tree->command) - 1] = '\0';
    }
}

int complete_tree(tree_t *bin_tree)
{
    char **opera_node = NULL;

    str_clean_parentheses(bin_tree);

    for (int i = 0; operator[i].op != NULL; i += 1) {
        if ((opera_node = opera_separa(bin_tree->command,
        operator[i].op)) != NULL) {
            add_new_opera_node(bin_tree, opera_node, operator[i].op);
            complete_tree(bin_tree->left);
            complete_tree(bin_tree->right);
            return (0);
        }
    }
    return (1);
}