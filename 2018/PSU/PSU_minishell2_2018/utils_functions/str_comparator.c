/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** str_comparator.c
*/

#include "utils_mini2.h"

int comp_word(char const *str1, char const *str2, int length)
{
    if (str1 == NULL || str2 == NULL)
        return (-1);
    for (int i = 0; (str1[i] != '\0' || str2[i] != '\0') && i < length; i += 1)
        if (str1[i] != str2[i]) {
            return (-1);
        }
    return (1);
}

int comp_word_right(char const *s1, char const *s2, int length)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (-1);
    for (; (s1[i] != '\0' || s2[i] != '\0') && i < length; i += 1)
        if (s1[i] != s2[i])
            return (-1);
    if (s2[i] != '\0') {
        return (-1);
    }
    return (1);
}

int comp_word_pre(char const *s1, char const *s2, int length)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (-1);
    for (; (s1[i] != '\0' || s2[i] != '\0') && i < length; i += 1)
        if (s1[i] != s2[i])
            return (-1);
    if (s1[i] != ' ' && s1[i] != '\t' && s1[i] != '\n' && s1[i] != '\0') {
        return (-1);
    }
    return (1);
}