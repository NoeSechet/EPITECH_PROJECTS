/*
** EPITECH PROJECT, 2019
** copy
** File description:
** copy
*/

#include "lib.h"

char *strcopy_pos(char *str, int begin)
{
    int size = 0;
    char *new_str = NULL;

    for (int j = begin; str[j] != '\0'; size++, j++);
    new_str = malloc(sizeof(char) * size + 1);
    for (int i = 0; str[begin] != '\0'; begin++, i++)
        new_str[i] = str[begin];
    new_str[size] = '\0';
    return (new_str);
}