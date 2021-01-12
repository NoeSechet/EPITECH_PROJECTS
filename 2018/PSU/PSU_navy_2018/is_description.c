/*
** EPITECH PROJECT, 2019
** description
** File description:
** description
*/

#include "utils.h"

void display_description(void)
{
    my_printf("USAGE\n");
    my_printf("\t./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n");
    my_printf("\tfirst_player_pid: only for the 2nd player.");
    my_printf(" pid of the first player.\n");
    my_printf("\tnavy_positions: ");
    my_printf("file representing the positions of the ships.\n");
}

int is_description(char *str)
{
    if (str_n_comp(str, "-h", my_strlen("-h") == 1)) {
        display_description();
        return (1);
    }
    return (0);
}