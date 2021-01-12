/*
** EPITECH PROJECT, 2019
** vector
** File description:
** vector
*/

#include "utils.h"

void *vector_get(vector_t *vector, int pos)
{
    return (vector->array[pos]);
}
