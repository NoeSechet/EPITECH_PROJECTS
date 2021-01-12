/*
** EPITECH PROJECT, 2019
** sort
** File description:
** sort
*/

#include "mysh.h"
#include "lib.h"
#include "struct_list.h"
#include "env_loc.h"

void sort_list_pieces(arraylist_t *list)
{
    env_loc_t *temp = NULL;

    for (int i = 0; i < list->nb_elem - 1;) {
        if (((env_loc_t *)list->array[i])->var[0]
        > ((env_loc_t *)list->array[i + 1])->var[0]) {
            temp = list->array[i];
            list->array[i] = list->array[i + 1];
            list->array[i + 1] = temp;
            i = 0;
        } else {
            i += 1;
        }
    }
}