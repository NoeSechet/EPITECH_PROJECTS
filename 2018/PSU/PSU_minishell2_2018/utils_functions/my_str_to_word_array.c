/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** my_str_to_word_array.c
*/

#include "utils_mini2.h"

char *fill_box(char *prog, int *parstr)
{
    char *box = NULL;
    int len = *parstr;
    int length_box = 0;
    int parser = 0;

    for (; (prog[*parstr] == ' ' || prog[*parstr] == '\t') &&
    prog[*parstr] != '\0'; prog += 1);
    for (; prog[len] != ' ' && prog[len] != '\0'; len += 1)
        length_box += 1;
    box = malloc(sizeof(char) * (length_box + 1));
    for (; prog[*parstr] != ' ' && prog[*parstr] != '\0' && prog[*parstr]
    != '\n' && prog[*parstr] != '\t'; parser += 1) {
        box[parser] = prog[*parstr];
        *parstr += 1;
    }
    box[parser] = '\0';
    for (; (prog[*parstr] == ' ' || prog[*parstr] == '\t')
        && prog[*parstr] != '\0'; *parstr += 1);
    return (box);
}

char **my_str_to_word_array(char *prog)
{
    int nb_boxes = get_nb_words(prog);
    char **tab = NULL;
    int parstr = 0;

    tab = malloc(sizeof(char *) * (nb_boxes + 1));
    for (int i = 0; i < nb_boxes; i += 1)
        tab[i] = fill_box(prog, &parstr);
    tab[nb_boxes] = NULL;
    return (tab);
}