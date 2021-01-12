/*
** EPITECH PROJECT, 2019
** simple_l_flag.c
** File description:
** simple_l_flag.c
*/

#include "utils.h"

void simple_l_flag(char *file, struct stat stat_info)
{
    stat(file, &stat_info);
    if (file[0] != '.') {
        type_protection_nb_link(stat_info);
        ownername_groupname(stat_info);
        size_in_octet(stat_info, 0);
        print_date(stat_info);
        my_printf("%s\n", file);
    }
}