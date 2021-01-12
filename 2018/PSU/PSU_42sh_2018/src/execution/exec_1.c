/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** exec_1.c
*/

#include "mysh.h"

int check_if_folder(char *input)
{
    struct stat st;

    lstat(input, &st);
    if (!access(input, X_OK) && S_ISDIR(st.st_mode)) {
        my_printf("%s: Permission denied.\n", input);
        return (1);
    } else
        return (0);
}

int exec_check(char **command, char **env, tree_t *tree, char **path)
{
    char *a = my_strcat("/", command[0]);

    for (int i = 0; path && path[i] != NULL; i++) {
        command[0] = my_strcat(path[i], a);
        if (access(command[0], X_OK) == 0) {
            free(a);
            return (my_fork(command, tree, env));
        }
    }
    free(a);
    return (1);
}

int exec_with_path(char **command, char **env, tree_t *tree, char **path)
{
    char *save = my_strdup(command[0]);
    int exec_fork = exec_check(command, env, tree, path);

    if (exec_fork != 1) {
        free(save);
        return (exec_fork);
    }
    if (access(command[0], X_OK) != 0)
        my_printf("%s: Command not found.\n", save);
    free_tabs(path);
    free(save);
    return (1);
}

int my_exec(main_list_t *main, char **command, tree_t *tree)
{
    char **path = !get_path(&main->env) ? main->sec_path :
    get_path(&main->env);
    char **env_tab = get_new_env(&main->env);
    char **new_cmd = NULL;
    int value_return = 0;

    if (!command || !command[0])
        return (0);
    else if ((new_cmd = check_alias(command, main->alias)) != NULL)
        return (my_exec_alias(main, new_cmd, tree));
    if (check_if_folder(command[0]) != 0)
        return (1);
    if (access(command[0], X_OK) == 0) {
        value_return = my_fork(command, tree, env_tab);
        main->value_return = value_return;
        return (value_return);
    }
    else if (access(command[0], X_OK) != 0)
        return (exec_with_path(command, env_tab, tree, path));
    return (0);
}
