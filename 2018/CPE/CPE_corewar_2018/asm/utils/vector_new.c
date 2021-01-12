/*
** EPITECH PROJECT, 2019
** vector
** File description:
** vector
*/

#include "utils.h"
#include "lib.h"

vector_t *vector_new(int n)
{
    vector_t *vector = malloc(sizeof(vector_t));

    vector->alloc = n;
    vector->nb_element = 0;
    vector->array = malloc(sizeof(void *) * n);
    return (vector);
}
