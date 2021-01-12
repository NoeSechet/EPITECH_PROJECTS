/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** create_arg_tab.c
*/

#include "lib.h"
#include "my_struct.h"

static const inhib_tab_t inhib_tab[] = {
    {'n', '\n'},
    {'t', '\t'},
    {'r', '\r'},
    {'b', '\b'},
    {'a', '\a'},
    {'0', '\0'},
    {'v', '\v'},
    {'f', '\f'},
    {0, 0},
};

int detect_inhib(char *input, int flag)
{
    for (int i = 0; inhib_tab[i].comp != 0; i += 1) {
        if (input[1] == inhib_tab[i].comp) {
            return (flag ? inhib_tab[i].comp : inhib_tab[i].inhib);
        }
    }
    return (0);
}

char *fill_quote_zone(char **input, char c, int len)
{
    char *res_arg = init_tab(len);
    char inhib = 0;

    *input += 1;
    for (int i = 0; *input[0] != '\0' && i < len; *input += 1, i += 1)
        if (*input[0] == '\\' && (inhib = detect_inhib(*input, 0))) {
            res_arg[i] = inhib;
            i += 1;
        } else if (my_strncmp(*input, "\\\\", 2) == 0 &&
        (inhib = detect_inhib(*input + 1, 1))) {
            res_arg[i] = *input[0];
            res_arg[i + 1] = inhib;
            i += 2;
        } else
            res_arg[i] = *input[0];
    if (*input[0] != '\0')
        *input += 1;
    for (; *input[0] != '\0' && (*input[0] == c ||
    *input[0] == '\t'); *input += 1);
    return (res_arg);
}

char *fill_std(char **input, char c, int len)
{
    char inhib = 0;

    char *res_arg = init_tab(len);
    for (int i = 0; i < len; *input += 1, i += 1) {
        if (my_strncmp(*input, "\\\\", 2) == 0 &&
        (inhib = detect_inhib(*input + 1, 0))) {
            res_arg[i] = inhib;
            i += 2;
        } else if (*input[0] == '\\' && (inhib = detect_inhib(*input, 1))) {
            res_arg[i] = inhib;
            i += 1;
        } else
            res_arg[i] = *input[0];
    }
    for (; *input[0] != '\0' && (*input[0] == c || *input[0] == '\t') &&
    *input[0] != '\'' && *input[0] != '\"'; *input += 1);
    return (res_arg);
}

char *fill_arg_box(char **input, char c)
{
    int len = 0;
    char *res_arg = 0;

    for (; (*input[0] == c || *input[0] == '\t') &&
    *input[0] != '\0'; *input += 1);
    if ((len = get_length(*input, c)) == 0)
        return (NULL);
    if (*input[0] != '\0' && (*input[0] == '\"' || *input[0] == '\'')) {
        res_arg = fill_quote_zone(input, c, len);
    } else
        res_arg = fill_std(input, c, len);

    res_arg[len] = '\0';
    return (res_arg);
}

char **create_arg_tab(char *str, char c)
{
    int nb_boxes = count_nb_arg(str, c);
    char **arg_tab = NULL;

    if (count_nb_quotes(str) == -1) {
        return (NULL);
    }
    arg_tab = init_arg_tab(nb_boxes);
    for (int i = 0; i < nb_boxes; i += 1) {
        arg_tab[i] = fill_arg_box(&str, c);
    }
    arg_tab[nb_boxes] = NULL;
    return (arg_tab);
}