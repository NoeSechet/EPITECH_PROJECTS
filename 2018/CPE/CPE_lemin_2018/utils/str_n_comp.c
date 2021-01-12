/*
** EPITECH PROJECT, 2019
** str_n_comp.c
** File description:
** str_n_comp.c
*/

#include "utils_lem_in.h"

int str_n_comp(char const *s1, char const *s2, int length)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (0);
    for (; (s1[i] != '\0' || s2[i] != '\0') || i < length; i += 1)
        if (s1[i] != s2[i])
            return (0);
    if (s1[i] != '\0')
        return (0);

    return (1);
}