/*
** EPITECH PROJECT, 2019
** vector
** File description:
** vector
*/

#include "utils.h"
#include "lib.h"

void vector_realloc(vector_t *vector)
{
    void ** new_array = NULL;

    vector->alloc = vector->alloc * 2;
    new_array = malloc(sizeof(void *) * vector->alloc);
    for (int it = 0; it < vector->nb_element; it++)
        new_array[it] = vector->array[it];
    free(vector->array);
    vector->array = new_array;
}
