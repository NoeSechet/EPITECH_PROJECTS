/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** utils.c
*/

#include "include/utils.h"

int comp_word(char const *str1, char const *str2, int length)
{
    if (str1 == NULL || str2 == NULL)
        return (-1);
    for (int i = 0; (str1[i] != '\0' || str2[i] != '\0') && i < length; i += 1)
        if (str1[i] != str2[i])
            return (-1);
    return (1);
}

int nb_words(char *line)
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
    int nb_boxes = nb_words(prog);
    char **tab = NULL;
    int parstr = 0;

    tab = malloc(sizeof(char *) * (nb_boxes + 1));
    for (int i = 0; i < nb_boxes; i += 1)
        tab[i] = fill_box(prog, &parstr);
    tab[nb_boxes] = NULL;
    return (tab);
}

char *get_environment_val(char *variable, list_t *list)
{
    char *value = NULL;

    for (elem_t *temp = list->start; temp != NULL; temp = temp->next)
        if (comp_word(variable, temp->str, my_strlen(variable)) == 1) {
            value = temp->str + my_strlen(variable) + 1;
            return (value);
        }
    return (NULL);
}