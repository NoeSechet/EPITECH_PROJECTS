/*
** EPITECH PROJECT, 2019
** com_exit.c
** File description:
** com_exit.c
*/

#include "utils_mini2.h"
#include "bin_tree.h"

int is_a_num(char *exit_arg)
{
    for (int i = 0; exit_arg[i] != '\0'; i += 1) {
        if ((exit_arg[i] < '0' || exit_arg[i] > '9') && exit_arg[i] != '\0')
            return (-1);
    }
    return (1);
}

void check_exit_error(char *exit_arg)
{
    if (exit_arg[0] >= '0' && exit_arg[0] <= '9')
        my_printf("exit: Badly formed number.\n");
    else
        my_printf("exit: Expression syntax.\n");
}

void simple_exit(char **tab, list_t *list)
{
    if (isatty(0) == 1)
        my_printf("exit\n");
    destroy_list(list);
    destroy_tab(tab);
    exit(0);
}

void exit_with_arg(char **tab, list_t *list)
{
    int copy_tab_1 = my_get_nbr(tab[1]);

    if (is_a_num(tab[1]) == 1) {
        if (isatty(0) == 1)
            my_printf("exit\n");
        destroy_list(list);
        destroy_tab(tab);
        exit(copy_tab_1);
    } else
        check_exit_error(tab[1]);
}

int com_exit(char **tab, list_t *list, int *fd)
{
    (void)fd;
    int word_count = 0;

    for (int i = 0; tab[i] != NULL; i += 1, word_count += 1);

    if (word_count > 2) {
        my_printf("exit: Expression syntax.\n");
        return (-1);
    }
    if (word_count == 1) {
        simple_exit(tab, list);
    } else {
        exit_with_arg(tab, list);
    }
    return (0);
}