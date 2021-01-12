/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** main
*/

#include "nm.h"

int launch_nm(int ac, char **files)
{
    symblist_t *list = NULL;

    for (size_t i = 1; files[i] != NULL; i += 1) {
        if ((list = get_symb(ac, files[i])) == NULL)
            continue;
        sort_symb_list(list);
        print_symb_list(list);
        free_symb_list(list);
    }
    return 0;
}

int main(int ac, char **av)
{
    int res = 0;

    if (ac == 1) {
        res = launch_nm(ac, (char *[]){ NULL, "a.out", NULL});
    } else if (ac > 1) {
        res = launch_nm(ac, av);
    } else {
        return 1;
    }
    return res;
}