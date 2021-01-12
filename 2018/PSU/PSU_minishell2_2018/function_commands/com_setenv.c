/*
** EPITECH PROJECT, 2019
** com_setenv.c
** File description:
** com_setenv.c
*/

#include "utils_mini2.h"
#include "mini_command.h"
#include "bin_tree.h"

void check_setenv_error(int word_count, char *variable)
{
    if (word_count > 3)
        my_printf("setenv: Too many arguments.\n");
    else if (first_is_a_letter(variable) != 1)
        my_printf("setenv: Variable name must begin with a letter.\n");
    else {
        my_printf("setenv: Variable name must");
        my_printf(" contain alphanumeric characters.\n");
    }
}

void re_set_variable(char *variable, list_t *list)
{
    for (elem_t *temp = list->start; temp != NULL; temp = temp->next)
        if (check_var(variable, temp->str, my_strlen(variable)) == 1) {
            free(temp->str);
            temp->str = fusion(variable, "=");
            return;
        }
    insert_element_at(list, fusion(variable, "="), list->length);
}

void change_variable(char **var_val_tab, list_t *list)
{
    for (elem_t *temp = list->start; temp != NULL; temp = temp->next)
        if (check_var(var_val_tab[1], temp->str,
        my_strlen(var_val_tab[1])) == 1) {
            free(temp->str);
            temp->str = fusion(fusion(var_val_tab[1], "="), var_val_tab[2]);
            return;
        }
    insert_element_at(list, fusion(fusion(var_val_tab[1], "="),
        var_val_tab[2]), list->length);
}

int com_setenv(char **tab, list_t *list, bin_tree_t *bin_tree)
{
    (void)bin_tree;
    int word_count = 0;

    for (int i = 0; tab[i] != NULL; i += 1, word_count += 1);
    if (word_count == 1) {
        com_env(tab, list, bin_tree);
        return (0);
    }
    if (word_count > 3 || first_is_a_letter(tab[1]) != 1 ||
    alphanum_char_only(tab[1]) != 1) {
        check_setenv_error(word_count, tab[1]);
        return (0);
    }
    if (word_count == 2)
        re_set_variable(tab[1], list);
    else if (word_count == 3)
        change_variable(tab, list);
    return (0);
}