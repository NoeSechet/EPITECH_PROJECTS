/*
** EPITECH PROJECT, 2019
** vector
** File description:
** vector
*/

#include "utils.h"
#include "lib.h"

void vector_pop(vector_t *vector, int i)
{
    if (i + 1 < vector->nb_element) {
        for (int it = i + 1; it <= vector->nb_element; it++) {
            vector->array[it - 1] = vector->array[it];
        }
        vector->nb_element -= 1;
    } else {
        vector->array[i] = NULL;
        vector->nb_element -= 1;
    }
}
