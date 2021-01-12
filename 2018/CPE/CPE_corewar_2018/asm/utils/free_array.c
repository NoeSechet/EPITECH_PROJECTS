/*
** EPITECH PROJECT, 2019
** free
** File description:
** free
*/

#include "lib.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}