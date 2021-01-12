/*
** EPITECH PROJECT, 2019
** vector
** File description:
** vector
*/

#include "utils.h"

void vector_push(vector_t *vector, void *element)
{
    if (vector->alloc == vector->nb_element) {
        vector_realloc(vector);
        vector_push(vector, (void *)element);
    } else {
        vector->array[vector->nb_element] = element;
        vector->nb_element += 1;
    }
}
