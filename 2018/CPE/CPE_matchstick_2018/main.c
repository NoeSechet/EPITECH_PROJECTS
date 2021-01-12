/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "include/utils.h"

int main(int ac, char const **av)
{
    if (ac != 3)
        return (84);
    int nb_line = my_get_nbr(av[1]);
    if (nb_line < 2 && nb_line > 99)
        return (84);
    int max_remov = my_get_nbr(av[2]);
    int *board = NULL;

    board = fill_board(nb_line);
    if (board == NULL)
        return (84);
    print_board(board, nb_line);
    return (player_interaction(board, nb_line, max_remov));
}