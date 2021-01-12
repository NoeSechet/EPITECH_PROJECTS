/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** which
*/

#include "mysh.h"

int find_which_vars(char **tab_buil, char *command, list_t *env, list_t *alias)
{
    char **path = get_path(env);
    char *copy = my_strdup(command);
    char *new_cmd = (command != NULL) ? my_strcat("/", command) : NULL;

    if (check_alias_which(alias, command) == 0)
        return (0);
    if (check_which_builtin(tab_buil, command) == 0) {
        my_printf("%s: shell built-in command.\n", command);
        return (0);
    }
    if (check_type_command_which(command) == 0)
        return (0);
    for (int i = 0; path && path[i] != NULL; i++) {
        command = my_strcat(path[i], new_cmd);
        if (check_type_command_which(command) == 0)
            return (0);
    }
    my_printf("%s: Command not found.\n", copy);
    return (1);
}

int loop_command(char **tab_input, char **tab_buil, list_t *env, list_t *alias)
{
    int ret = 0;
    int check_ret = 0;

    for (int i = 0; tab_input && tab_input[i] != NULL; i++) {
        ret = find_which_vars(tab_buil, tab_input[i], env, alias);
        if (ret == 1)
            check_ret = ret;
    }
    return (check_ret);
}

int my_which(main_list_t *main, tree_t *tree, char **input)
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
        return (find_which_vars(tab_buil, input[1], &main->env, main->alias));
    else
        return (loop_command(input + 1, tab_buil, &main->env, main->alias));
}
