/*
** EPITECH PROJECT, 2019
** is
** File description:
** is
*/

#include "mysh.h"
#include "lib.h"
#include "struct_list.h"
#include "env_loc.h"

int is_flag(char *str)
{
    if (my_strcmp(str, "-n") == 0)
        return (true);
    if (my_strcmp(str, "-e") == 0)
        return (true);
    return (false);
}

int is_var_env_loc(char *cmd, main_list_t *list)
{
    for (int i = 0;  i < list->env_loc->nb_elem; i++) {
        if (strcmp(cmd, ((env_loc_t *)list->env_loc->array[i])->var) == 0) {
            return (true);
        }
    }
    return (false);
}

int is_var_env(char *command, main_list_t *list)
{
    char **array = NULL;

    for (elem_t *tmp = list->env.start; tmp != NULL; tmp = tmp->next) {
        array = my_str_to_word_array(tmp->data, '=');
        if (strcmp(array[0], command) == 0) {
            free(command);
            free_tabs(array);
            return (true);
        }
        free_tabs(array);
    }
    return (false);
}