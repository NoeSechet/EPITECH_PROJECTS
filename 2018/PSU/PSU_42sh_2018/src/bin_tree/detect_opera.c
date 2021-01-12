/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** detect_opera.c
*/

#include "lib.h"

void skip_parantheses(char *opera, int *opera_pos)
{
    while (opera[*opera_pos] != '(' && *opera_pos > 0) {
        *opera_pos -= 1;
    }
}

int detect_opera(char *input, char *opera)
{
    int opera_pos = 0;

    if (!input)
        return (0);

    opera_pos = strlen(input) - strlen(opera);

    for (; opera_pos >= 0; opera_pos -= 1) {
        if (input[opera_pos + strlen(opera) - 1] ==  ')') {
            skip_parantheses(opera, &opera_pos);
        }
        if (my_strncmp(input + opera_pos, opera, strlen(opera)) == 0) {
            return (opera_pos);
        }
    }
    return (0);
}