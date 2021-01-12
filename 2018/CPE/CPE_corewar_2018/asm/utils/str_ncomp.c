/*
** EPITECH PROJECT, 2019
** str
** File description:
** str
*/

#include "utils.h"

int str_ncomp(char *str1, char *str2, int length)
{
    int i = 0;

    for (; (str1[i] != '\0' || str2[i] != '\0') && i < length; i++) {
        if (str1[i] != str2[i])
            return (-1);
    }
    if (str1[i] != '\0' && str1[i] != '\n' && str1[i] != '\t'
    && str1[i] != ' ')
        return (-1);
    return (1);
}
