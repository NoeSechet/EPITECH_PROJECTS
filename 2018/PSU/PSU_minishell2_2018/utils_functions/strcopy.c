/*
** EPITECH PROJECT, 2019
** strcopy
** File description:
** strcopy
*/

#include "utils_mini2.h"

char *strcopy(char *str)
{
    char *result = malloc(sizeof(char) * my_strlen(str) + 1);

    for (int i = 0; str[i] != '\0'; i++)
        result[i] = str[i];
    result[my_strlen(str)] = '\0';
    return (result);
}