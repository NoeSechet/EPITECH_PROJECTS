/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** create_arg_tab_utils.c
*/

#include "lib.h"

char *init_tab(int len)
{
    char *new_tab = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len + 1; i += 1)
        new_tab[i] = 0;

    new_tab[len] = '\0';
    return (new_tab);
}

char **init_arg_tab(int nb_boxes)
{
    char **arg_tab = malloc(sizeof(char *) * (nb_boxes + 1));

    for (int i = 0; i < nb_boxes; i += 1)
        arg_tab[i] = NULL;
    arg_tab[nb_boxes] = NULL;
    return (arg_tab);
}

int skip_quote_zone(char **temp, char memo, char c)
{
    int counter = 0;

    *temp += 1;
    for (; *temp[0] != memo && *temp[0] != '\0'; *temp += 1)
        counter += 1;
    if (*temp[0] != '\0')
        *temp += 1;
    for (; *temp[0] != '\0' && (*temp[0] == c ||
        *temp[0] == '\t'); *temp += 1);

    return (counter);
}

void next_word(char **temp, char c)
{
    for (; *temp[0] != '\0' && *temp[0] != c && *temp[0] != '\t' &&
    *temp[0] != '\'' && *temp[0] != '\"'; *temp += 1);
    for (; *temp[0] != '\0' && (*temp[0] == c || *temp[0] == '\t') &&
    *temp[0] != '\'' && *temp[0] != '\"'; *temp += 1);
}

int count_nb_arg(char *line, char c)
{
    int word_count = 0;
    char memo = 0;
    char *temp = line;

    if (!temp)
        return (0);
    for (; (temp[0] == c || temp[0] == '\t') && temp[0] != '\0'; temp += 1);
    for (; temp[0] != '\0'; )
        if ((temp[0] == '\'') || (temp[0] == '\"')) {
            memo = temp[0];
            word_count += skip_quote_zone(&temp, memo, c) > 0 ? 1 : 0;
            continue;
        } else {
            next_word(&temp, c);
            word_count += 1;
            continue;
        }
    return (word_count);
}