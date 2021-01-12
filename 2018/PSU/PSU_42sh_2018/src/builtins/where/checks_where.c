/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** sl
*/

#include "mysh.h"

int check_builtin(char **tab_built, char *cmd)
{
    if (!tab_built || !cmd)
        return (1);
    for (int i = 0; tab_built[i] != NULL; i++)
        if (my_strcmp(cmd, tab_built[i]) == 0) {
            my_printf("%s is a shell built-in\n", cmd);
            return (0);
        }
    return (1);
}

int check_type_command(char *command)
{
    if (access(command, X_OK | F_OK) == 0) {
        my_printf("%s\n", command);
        return (0);
    } else
        return (1);
}

int check_alias_where(list_t *alias, char *cmd)
{
    elem_t *elem = alias->start;
    char **data = NULL;

    for (; elem != NULL; elem = elem->next) {
        data = my_str_to_word_array(elem->data, '=');
        if (my_strcmp(str_clean(data[0]), cmd) == 0) {
            my_printf("%s aliased to %s\n", cmd, str_clean(data[1]));
            free_tabs(data);
            return (0);
        }
    }
    return (1);
}
