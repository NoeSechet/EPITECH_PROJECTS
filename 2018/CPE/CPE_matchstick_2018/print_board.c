/*
** EPITECH PROJECT, 2019
** print_board.c
** File description:
** print_board.c
*/

#include "include/utils.h"

void print_space(int max_length, int line_nbr)
{
    int nbr_pipe = (line_nbr - 1) * 2 + 1;
    int nbr_space = (max_length - nbr_pipe - 2) / 2;

    for (int i = 0; i < nbr_space; i += 1)
        write(1, " ", 1);
}

void print_pipe(int line_nbr, int nb_sticks)
{
    int initial_nbr_sticks = (line_nbr - 1) * 2 + 1;

    for (int i = 0; i < (nb_sticks); i += 1)
        write(1, "|", 1);
    for (int i = 0; i < initial_nbr_sticks - (nb_sticks); i += 1)
        write(1, " ", 1);
}

void print_board(int *board, int nb_line)
{
    int max_length = (nb_line - 1) * 2 + 3;

    for (int i = 0; i < max_length; i += 1)
        write(1, "*", 1);
    write(1, "\n", 1);
    for (int k = 1; k <= nb_line; k += 1) {
        write(1, "*", 1);
        print_space(max_length, k);
        print_pipe(k, board[k - 1]);
        print_space(max_length, k);
        write(1, "*\n", 2);
    }
    for (int i = 0; i < max_length; i += 1)
        write(1, "*", 1);
    write(1, "\n\n", 2);
}