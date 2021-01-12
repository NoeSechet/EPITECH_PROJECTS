/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** execution.c
*/

#include "mysh.h"

static const execution_t tab_exec[] = {
    {"||", &exec_or},
    {"&&", &exec_and},
    {"<", &exec_left_redirection},
    {">", &exec_right_redirection},
    {">>", &exec_double_redirection_right},
    {"<<", &exec_double_redirection_left},
    {";", &exec_semi_colomn},
    {NULL, NULL}
};

int exec_semi_colomn(tree_t *tree, main_list_t *main_list)
{
    int fd2[2];

    fd2[0] = dup(0);
    fd2[1] = dup(1);
    dup2(tree->fd[0], 0);
    dup2(tree->fd[1], 1);
    do_execution(tree->left, main_list);
    do_execution(tree->right, main_list);
    check_dup(tree, fd2);
    return (0);
}

int type_exec(main_list_t *main_list, tree_t *tree)
{
    int i = 0;
    char **builtin_tab = create_arg_tab(tree->command, ' ');
    char **ex_tab = NULL;

    if (builtin_tab == NULL)
        return (1);
    builtin_tab = my_globbings(builtin_tab);
    check_var_inter(main_list, builtin_tab);
    if ((i = find_builtin(main_list, builtin_tab, tree)) == -1) {
        ex_tab = my_str_to_word_array(tree->command, ' ');
        ex_tab = my_globbings(ex_tab);
        check_var_inter(main_list, ex_tab);
        i = my_exec(main_list, ex_tab, tree);
    }
    return (i);
}

int do_execution(tree_t *tree, main_list_t *main_list)
{
    for (int i = 0; tree != NULL && tree->opera != NULL &&
    tab_exec[i].func != NULL; i++) {
        if (my_strcmp(tree->opera, "|") == 0) {
            tree->left->fd[0] = tree->fd[0];
            tree->right->fd[1] = tree->fd[1];
            return (exec_pipe(tree, main_list));
        }
        if (my_strcmp(tree->opera, tab_exec[i].opperator) == 0)
            return (tab_exec[i].func(tree, main_list));
    }
    return (type_exec(main_list, tree));
}

int execution(main_list_t *main)
{
    tree_t *tree = create_new_node(main->str);
    int i = 0;

    if (valid_str(str_clean(main->str)) == 1)
        return (1);
    complete_tree(tree);
    i = do_execution(tree, main);
    destroy_tree(tree);
    return (i);
}
