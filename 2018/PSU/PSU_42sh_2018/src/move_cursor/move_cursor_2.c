/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** move_cursor
*/

#include "mysh.h"

char *add_changes(char *dest, char *src, int pos)
{
    int c = 0;
    int c2 = 0;
    int nb = 0;
    char *str = malloc(sizeof(char) * (strlen(dest) + strlen(src) + 1));

    if (my_strlen(dest) + 1 == pos) {
        for (; dest[c]; c += 1, nb += 1)
            str[nb] = dest[c];
        for (; src[c2]; c2 += 1, nb += 1)
            str[nb] = src[c2];
    } else {
        for (; c != pos - 1; c += 1, nb += 1)
            str[nb] = dest[c];
        for (; src[c2]; c2 += 1, nb += 1)
            str[nb] = src[c2];
        for (; dest[c]; c += 1, nb += 1)
            str[nb] = dest[c];
    }
    str[nb] = '\0';
    return (str);
}
