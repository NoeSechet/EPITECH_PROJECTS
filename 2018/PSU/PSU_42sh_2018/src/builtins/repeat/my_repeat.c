/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my_repeat
*/

#include "mysh.h"

char **fill_tab(char **input)
{
    char **ex_tab = malloc(sizeof(char *) * (my_tablen(input) + 1));
    int i = 0;

    for (; input[i] != NULL; i++)
        ex_tab[i] = my_strdup(input[i]);
    ex_tab[i] = NULL;
    return (ex_tab);
}

int my_repeat(main_list_t *main, tree_t *tree, char **input)
{
    (void)tree;
    int nb_occur = 0;
    int ret_value = 0;
    char *new_str = str_clean(main->str);
    tree_t *new_tree = NULL;

    if (error_repeat(input) != 0)
        return (1);
    new_tree = create_new_node(new_str + my_strlen(input[0]) +
    my_strlen(input[1]) + 2);
    nb_occur = atoi(input[1]);
    complete_tree(new_tree);
    for (int i = 0; i < nb_occur; i++)
        ret_value = do_execution((new_tree->left != NULL) ?
        new_tree->left : new_tree, main);
    return (ret_value);
}
