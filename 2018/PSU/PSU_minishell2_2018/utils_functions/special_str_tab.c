/*
** EPITECH PROJECT, 2019
** special_str_tab.c
** File description:
** special_str_tab.c
*/

#include "utils_mini2.h"

int count_nb_separator(char *line, char c)
{
    int word_count = 0;

    if (!line)
        return (0);
    for (; line[0] == c && line[0] != '\0'; line += 1);
    for (int i = 0; line[i] != '\0'; i += 1)
        if ((line[i + 1] != '\0' && line[i + 1] != c && line[i + 1] != '\n')
        && line[i] == c)
            word_count += 1;

    return (word_count + 1);
}

char *str_fill_box(char *prog, int *parstr, char c)
{
    char *box = NULL;
    int len = *parstr;
    int length_box = 0;
    int parser = 0;

    for (; prog[0] == c && prog[0] != '\0'; prog += 1);
    for (; prog[len] != c && prog[len] != '\0'; len += 1)
        length_box += 1;
    box = malloc(sizeof(char) * (length_box + 1));
    for (; prog[*parstr] != c && prog[*parstr] != '\n'
    && prog[*parstr] != '\0'; parser += 1) {
        box[parser] = prog[*parstr];
        *parstr += 1;
    }
    box[length_box] = '\0';
    for (; prog[*parstr] == c && prog[*parstr] != '\0'; *parstr += 1);
    return (box);
}

char **special_str_tab(char *str, char c)
{
    int nb_boxes = count_nb_separator(str, c);
    char **tab = NULL;
    int parstr = 0;

    tab = malloc(sizeof(char *) * (nb_boxes + 1));
    for (int i = 0; i < nb_boxes; i += 1)
        tab[i] = str_fill_box(str, &parstr, c);
    tab[nb_boxes] = NULL;
    return (tab);
}
