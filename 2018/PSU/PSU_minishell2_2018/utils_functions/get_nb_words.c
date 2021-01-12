/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** get_nb_words.c
*/

#include "utils_mini2.h"

int get_nb_words(char *line)
{
    int word_count = 0;

    for (; (line[0] == ' ' || line[0] == '\t') && line[0] != '\0'; line += 1);
    for (int i = 0; line[i] != '\0'; i += 1)
        if ((line[i + 1] != '\0' && line[i + 1] != ' ' &&
        line[i + 1] != '\t' && line[i + 1] != '\n') &&
        ((line[i] == ' ' || line[i] == '\t') && line[i] != '\n'))
            word_count += 1;
    return (word_count + 1);
}