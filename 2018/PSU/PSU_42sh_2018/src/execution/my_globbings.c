/*
** EPITECH PROJECT, 2018
** Functions for globbings
** File description:
** my_globbings.c
*/

#include "mysh.h"

char **remove_hiden_globbings(char **input)
{
    int nb_files = 0;
    char **new_inp = NULL;

    for (int idx = 0; input[idx] != NULL; ++idx)
        if (input[idx][0] != '.')
            nb_files++;
    new_inp = malloc(sizeof(char *) * (nb_files + 1));
    new_inp[nb_files] = NULL;
    for (int idx = 0, k = 0; input[k] != NULL; ++k) {
        if (input[k][0] != '.')
            new_inp[idx++] = my_strdup(input[k]);
    }
    free_tabs(input);
    input = NULL;
    return (new_inp);
}

char **get_globbings(char *arg)
{
    glob_t globbing;
    char **new_inp = NULL;

    if (arg == NULL)
        return (NULL);
    else if (my_strcmp(arg, "..") == 0) {
        new_inp = my_str_to_word_array(arg, ' ');
        return (new_inp);
    }
    if (glob(arg, GLOB_PERIOD | GLOB_NOSORT | GLOB_NOCHECK | GLOB_NOMAGIC,
    NULL, &globbing) == GLOB_NOMATCH)
        return (NULL);
    new_inp = my_tabdup(globbing.gl_pathv);
    new_inp = remove_hiden_globbings(new_inp);
    globfree(&globbing);
    return (new_inp);
}

char **my_globbings(char **input)
{
    char **new_inp = NULL;
    char **temp_tab = NULL;

    if (input == NULL || my_tablen(input) == 1)
        return (input);
    for (int idx = 0; input[idx] != NULL; ++idx) {
        temp_tab = get_globbings(input[idx]);
        new_inp = my_tabcat(new_inp, temp_tab);
        free_tabs(temp_tab);
        temp_tab = NULL;
    }
    free_tabs(input);
    return (new_inp);
}