/*
** EPITECH PROJECT, 2019
** vector
** File description:
** vector
*/

#include "utils.h"
#include "lib.h"

void vector_free(vector_t *vector)
{
    for (int i = 0; i < vector->nb_element; i++)
        free(vector->array[i]);
    free(vector->array);
    free(vector);
}