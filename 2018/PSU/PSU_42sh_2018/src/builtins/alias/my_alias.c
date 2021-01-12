/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my_alias
*/

#include "mysh.h"

void print_alias_list(list_t *alias)
{
    for (elem_t *elem = alias->start; elem != NULL; elem = elem->next)
        my_printf("%s\n", elem->data);
}

void remove_if_aliased(list_t *alias, char *input)
{
    char **alias_tab = NULL;

    for (elem_t *elem = alias->start; elem != NULL; elem = elem->next) {
        alias_tab = my_str_to_word_array(elem->data, '=');
        while ((my_strlen(alias_tab[0]) - 1 != 0) && \
        alias_tab[0][my_strlen(alias_tab[0]) - 1] == ' ')
            alias_tab[0][my_strlen(alias_tab[0]) - 1] = 0;
        if (my_strcmp(alias_tab[0], input) == 0) {
            pop_elem(alias, elem);
            free_tabs(alias_tab);
            return;
        }
        free_tabs(alias_tab);
        alias_tab = NULL;
    }
}

char *remove_quotes_alias(char *str)
{
    if (str == NULL || str[0] != '"')
        return (str);
    str[my_strlen(str) - 1] = 0;
    for (int idx = 0; str[idx + 1] != 0; ++idx)
        str[idx] = str[idx + 1];
    str[my_strlen(str) - 1] = 0;
    return (str);
}

void stock_alias(list_t *alias, char **input)
{
    char *alias_str = NULL;

    input[0] = remove_quotes_alias(input[0]);
    alias_str = my_strcat(input[0], " = ");
    remove_if_aliased(alias, input[0]);
    for (int idx = 1; input[idx] != NULL; ++idx) {
        if (idx != 1)
            alias_str = my_strcat(alias_str, " ");
        input[idx] = remove_quotes_alias(input[idx]);
        alias_str = my_strcat(alias_str, input[idx]);
    }
    push_back_haroun(alias, alias_str);
    sort_list(alias);
}

int my_alias(main_list_t *main, tree_t *tree, char **input)
{
    (void) tree;
    int size = my_tablen(input);

    switch (size) {
        case 0: return (-1);
        case 1: print_alias_list(main->alias); break;
        case 2: break;
        default: stock_alias(main->alias, (input + 1)); break;
    }
    return (0);
}
