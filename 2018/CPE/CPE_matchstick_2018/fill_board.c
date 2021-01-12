/*
** EPITECH PROJECT, 2019
** print_game_board.c
** File description:
** print_game_board.c
*/

#include "include/utils.h"

int *fill_board(int nb_line)
{
    int *board = malloc(sizeof(int) * (nb_line));
    if (board == NULL)
        return NULL;
    if (nb_line > 0)
        board[0] = 1;
    else
        return (NULL);
    for (int i = 1; i < nb_line; i += 1)
        board[i] = (i + 1) * 2 - 1;
    return (board);
}