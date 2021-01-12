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

int is_arg_spaced(char **input, main_list_t *list, int *i)
{
    char *tmp = NULL;

    if (get_nb_str_array(input) > *i + 1
    && strcmp(input[*i + 1], "=") == 0) {
        tmp = fusion(input[*i], input[*i+1]);
        *i += 1;
        if (get_nb_str_array(input) > *i + 1) {
            tmp = fusion(tmp, input[*i + 1]);
            *i += 1;
        }
        if (set_var(tmp, list) == (-1))
            return (-1);
        free(tmp);
        sort_list_pieces(list->env_loc);
        return (true);
    }
    return (false);
}