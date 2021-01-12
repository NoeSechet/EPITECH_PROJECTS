/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** cd
*/

#include "mysh.h"

int exec_cd(list_t *list, char **input, char *old_pwd)
{
    char *buf = input[1];
    int ret = 0;

    if (buf && buf[0] == '-') {
        (old_pwd == NULL) ? (ret = 1) : (ret = chdir(old_pwd));
        (ret == 0) ? change_env(list) : 0;
    } else if (buf && buf[0] != '-') {
        ret = chdir(buf);
        (ret == 0) ? change_env(list) : 0;
    } else {
        ret = chdir(get_from_env(list, "HOME") + 5);
        (ret == 0) ? change_env(list) : 0;
    }
    return (ret);
}

int my_cd(main_list_t *main, tree_t *tree, char **input)
{
    (void)tree;
    int ret = 0;
    char directory[4096];
    static char *old_pwd = NULL;

    if (my_tablen(input) > 2) {
        my_printf("cd: Too many arguments.\n");
        return (1);
    }
    (!getcwd(directory, 4096)) ? directory[0] = 0 : 0;
    if (input[1] && (my_strcmp(input[1], "~") == 0 ||
        my_strcmp(input[1], "home") == 0)) {
        (my_strcmp(input[1], "home") == 0) ? my_printf("~ \n") : 0;
        ret = chdir(get_from_env(&main->env, "HOME") + 5);
        (ret == 0) ? change_env(&main->env) : 0;
    } else
        ret = exec_cd(&main->env, input, old_pwd);
    if (directory[0])
        (ret == 0) ? old_pwd = my_strdup(directory) : 0;
    return (gest_error(input[1], ret));
}
