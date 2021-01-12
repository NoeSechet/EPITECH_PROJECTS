/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** exec_alias.c
*/

#include "mysh.h"

char **replace_by_alias(char *data, char **cmd)
{
    char **datab = my_str_to_word_array(data, '=');
    char *als_cmd = NULL;

    if (datab == NULL)
        return (NULL);
    als_cmd = my_strdup(datab[1]);
    free_tabs(datab);
    datab = NULL;
    datab = my_str_to_word_array(als_cmd, ' ');
    datab = my_tabcat(datab, cmd);
    return (datab);
}

int my_exec_alias(main_list_t *main_list, char **command, tree_t *tree)
{
    char **path = get_path(&main_list->env);
    char **env_tab = get_new_env(&main_list->env);
    char **new_cmd = NULL;

    if (check_alias_loop(main_list->alias, command[0], command[0]) == 1) {
        write(2, "Alias loop.\n", 12);
        return (1);
    }
    if (!command || !command[0])
        return (0);
    else if ((new_cmd = check_alias(command, main_list->alias)) != NULL)
        return (my_exec_alias(main_list, new_cmd, tree));
    if (check_if_folder(command[0]) != 0)
        return (1);
    if (access(command[0], X_OK) == 0)
        return (my_fork(command, tree, env_tab));
    else if (access(command[0], X_OK) != 0)
        return (exec_with_path(command, env_tab, tree, path));
    return (0);
}

char *get_alias_cmd(char *data)
{
    char *als = malloc(sizeof(char) * my_strlen(data));
    int idx = 0;

    for (; data[idx] != 0 && data[idx + 1] != '='; ++idx)
        als[idx] = data[idx];
    als[idx] = 0;
    return (als);
}

char **check_alias(char **cmd, list_t *alias)
{
    char *als = NULL;

    if (alias == NULL || alias->end == NULL || alias->start == NULL)
        return (NULL);
    for (elem_t *elem = alias->start; elem != NULL; elem = elem->next) {
        als = get_alias_cmd(elem->data);
        if (my_strcmp(als, cmd[0]) == 0)
            return (replace_by_alias(elem->data, (cmd + 1)));
        free(als);
        als = NULL;
    }
    return (NULL);
}
