/*
** EPITECH PROJECT, 2019
** utils_bis_bis.c
** File description:
** utils_bis_bis.c
*/

#include "utils_mini2.h"

int check_var(char const *s1, char const *s2, int length)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (-1);
    for (; (s1[i] != '\0' || s2[i] != '\0') && i < length; i += 1)
        if (s1[i] != s2[i])
            return (-1);
    if (s2[i] != '=')
        return (-1);
    return (1);
}

int first_is_a_letter(char *str)
{
    if (!str)
        return (0);
    if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z'))
        return (1);
    return (0);
}

int alphanum_char_only(char *str)
{
    if (!str)
        return (0);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')
        && (str[i] < '0' || str[i] > '9'))
            return (-1);
    }
    return (1);
}