/*
** EPITECH PROJECT, 2019
** convert_int_into_pos.c
** File description:
** convert_int_into_pos.c
*/

#include "include/utils.h"

char *convert_int_into_pos(int pos)
{
    char letter = (pos % 8);
    char nbr = (pos / 8);
    char *res_pos = malloc(sizeof(char) * 2 + 1);
    char i = 65;
    char j = 48;

    for (; i < 64 + letter; i += 1);
    for (; j < 49 + nbr; j += 1);

    res_pos[0] = i;
    res_pos[1] = j;
    res_pos[2] = '\0';
    return (res_pos);
}