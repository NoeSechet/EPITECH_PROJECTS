/*
** EPITECH PROJECT, 2019
** unset
** File description:
** unset
*/

#include "mysh.h"
#include "lib.h"
#include "struct_list.h"
#include "env_loc.h"

int my_unset(main_list_t *list, tree_t *tree, char **input)
{
    (void)tree;

    if (get_nb_str_array(input) == 1) {
        my_printf("unset: Too few arguments.\n");
        return (1);
    }
    for (int i = 1; input[i] != NULL; i++) {
        for (int j = 0;  j < list->env_loc->nb_elem; j++) {
            if (strcmp(input[i],
            ((env_loc_t *)list->env_loc->array[j])->var) == 0) {
                remove_elem_at(list->env_loc, j);
                break;
            }
        }
    }
    return (0);
}