/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my_where
*/

#include "mysh.h"

int check_command_where(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '/')
            return (1);
    return (0);
}

int find_where_vars(char **tab_buil, char *command, list_t *env, list_t *alias)
{
    char **path = get_path(env);
    char *new_cmd = (command != NULL) ? my_strcat("/", command) : NULL;
    int i = 0;

    if (check_command_where(command) == 1) {
        my_printf("where: / in command makes no sense\n");
        return (1);
    }
    check_alias_where(alias, command);
    if (check_builtin(tab_buil, command) == 0)
        i = 1;
    if (check_type_command(command) == 0)
        return (0);
    for (int i = 0; path && path[i] != NULL; i++) {
        command = my_strcat(path[i], new_cmd);
        if (check_type_command(command) == 0)
            return (0);
    }
    return (i != 1 ? 1 : 0);
}

int loop_cmd(char **tab_input, char **tab_built, list_t *env, list_t *alias)
{
    int ret = 0;
    int check_ret;

    for (int i = 0; tab_input && tab_input[i] != NULL; i++) {
        ret = find_where_vars(tab_built, tab_input[i], env, alias);
        if (ret == 1)
            check_ret = ret;
    }
    return (check_ret);
}

int my_where(main_list_t *main, tree_t *tree, char **input)
{
    char *tab_buil[] = {"echo", "cd", "setenv", "unsetenv", "env", "alias",
    "set", "unset", "which", "where", "history", "foreach", "repeat", "unalias"
    "wait", "logout", "pushd", "popd", "kill", "jobs", "help", "exit", "fg",
    "exec", "eval", "dirs", "continue", "complete", "break", "bg", "source",
    ":", "umask", "suspend", "shift", NULL};
    (void)tree;

    if (my_tablen(input) < 2) {
        my_printf("%s: Too few arguments.\n", input[0]);
        return (1);
    } else if (my_tablen(input) == 2)
        return (find_where_vars(tab_buil, input[1], &main->env, main->alias));
    else
        return (loop_cmd(input + 1, tab_buil, &main->env, main->alias));
}
