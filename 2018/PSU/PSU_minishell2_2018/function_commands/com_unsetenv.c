/*
** EPITECH PROJECT, 2019
** com_unsetenv.c
** File description:
** com_unsetenv.c
*/

#include "utils_mini2.h"
#include "bin_tree.h"

void delete_variable(char **var_val_tab, list_t *list)
{
    int j = 1;

    for (int i = 1; var_val_tab[i] != NULL; i += 1) {
        for (elem_t *temp = list->start; temp != NULL; temp = temp->next, j++)
            if (check_var(var_val_tab[i], temp->str,
            my_strlen(var_val_tab[i])) == 1) {
                pop_element_at(list, j);
                j = 1;
                break;
            }
    }
}

int com_unsetenv(char **tab, list_t *list, bin_tree_t *bin_tree)
{
    (void)bin_tree;
    int word_count = 0;

    for (int i = 0; tab[i] != NULL; i += 1, word_count += 1);

    if (word_count == 1) {
        my_printf("unsetenv: Too few arguments.\n");
        return (0);
    } else
        delete_variable(tab, list);
    return (0);
}