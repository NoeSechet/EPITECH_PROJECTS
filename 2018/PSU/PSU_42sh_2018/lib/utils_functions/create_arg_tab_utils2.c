/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** create_arg_tab_utils2.c
*/

#include "lib.h"

int count_pair(char **input, char memo)
{
    int pair = 1;

    *input += 1;
    for (; *input[0] != memo && *input[0] != '\0'; *input += 1);
    if (*input[0] == memo && *input[0] != '\0') {
        pair += 1;
    }
    return (pair % 2);
}

char count_nb_quotes(char *input)
{
    char memo = 0;

    if (!input)
        return (-1);
    for (; input[0] != '\0'; input += 1) {
        if ((input[0] == '\'') || (input[0] == '\"')) {
            memo = input[0];
            if (count_pair(&input, memo)) {
                my_printf("Unmatched '%c'.\n", (memo == 34 ? 34 : 39));
                return (-1);
            }
        }
        if (input[0] == '\0')
            break;
    }
    return (1);
}

int get_length_quote_zone(char **input, char memo, char c)
{
    int len = 0;

    *input += 1;
    for (; *input[0] != memo && *input[0] != '\0'; *input += 1)
        len += 1;
    if (*input[0] != '\0')
        *input += 1;
    for (; *input[0] != '\0' && (*input[0] == c ||
    *input[0] == '\t'); *input += 1);

    return (len);
}

int get_length_std(char **input, char c)
{
    int len = 0;

    for (; *input[0] != '\0' && *input[0] != c && *input[0] != '\t' &&
    *input[0] != '\'' && *input[0] != '\"'; *input += 1)
        len += 1;
    for (; *input[0] != '\0' && (*input[0] == c || *input[0] == '\t') &&
    *input[0] != '\'' && *input[0] != '\"'; *input += 1);

    return (len);
}

int get_length(char *input, char c)
{
    int len = 0;
    char memo = 0;

    if (input[0] == '\"' || input[0] == '\'') {
        memo = input[0];
        len = get_length_quote_zone(&input, memo, c);
    } else
        len = get_length_std(&input, c);

    return (len);
}