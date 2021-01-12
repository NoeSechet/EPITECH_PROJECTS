/*
** EPITECH PROJECT, 2019
** set
** File description:
** set
*/

#include "mysh.h"
#include "lib.h"
#include "struct_list.h"
#include "env_loc.h"

void neutralise_var(char **array, main_list_t *list)
{
    if (is_exist(array[0], list) == true) {
        update_value_env_loc(array[0], NULL, list);
        free_tabs(array);
        return;
    } else
        add_env_local(list, array[0], NULL);
    free_tabs(array);
}

int set_var(char *arg, main_list_t *list)
{
    char **array = sep_to_array(arg, '=');

    if (array[0] == NULL || array[0][0] < 97 || array[0][0] > 122)
        return (-1);
    if (get_nb_str_array(array) == 2 && array[1] != NULL) {
        if (is_exist(array[0], list) == true) {
            update_value_env_loc(array[0], array[1], list);
            free_tabs(array);
            return (0);
        }
        add_env_local(list, array[0], array[1]);
        free_tabs(array);
        return (0);
    }
    neutralise_var(array, list);
    return (0);
}