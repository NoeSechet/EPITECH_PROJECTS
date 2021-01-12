/*
** EPITECH PROJECT, 2019
** str
** File description:
** str
*/

#include "utils.h"
#include "lib.h"

int get_pos_begin(char *str, char s)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == s)
            return (i);
    }
    return (0);
}

int get_pos_end(char *str, char s)
{
    int pos = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == s)
            pos = i;
    }
    return (pos);
}

int is_two_s(char *str, char s)
{
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == s)
            index += 1;
    }
    if (index != 2)
        return (84);
    return (0);
}

char *strcopy_spe(char *str, char s)
{
    int begin = get_pos_begin(str, s);
    int end = get_pos_end(str, s);
    int total = 0;
    char *new_str = NULL;
    int j = 0;

    if (is_two_s(str, s) == 84)
        return NULL;
    for (int i = begin; i <= end - 2; i++)
        total += 1;
    new_str = malloc(sizeof(char *) * total + 1);
    for (; begin + 1 < end; j++, begin++)
        new_str [j] = str[begin + 1];
    new_str[j] = '\0';
    return (new_str);
}