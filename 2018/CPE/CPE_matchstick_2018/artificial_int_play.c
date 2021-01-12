/*
** EPITECH PROJECT, 2019
** artificial_int_play.c
** File description:
** artificial_int_play.c
*/

#include "include/utils.h"

int calc_nb_sticks(int *board, int nb_line)
{
    int total = 0;

    for (int i = 0; i < nb_line; i += 1)
        total += board[i];
    return (total);
}

int *simple_artificial_play(int *board, int nb_line, int max_remov)
{
    int *changes = malloc(sizeof(int) * 2);

    for (; max_remov > 0; max_remov -= 1)
        for (int i = 0; i < nb_line; i += 1)
            if (board[i] >= max_remov) {
                changes[0] = i + 1;
                changes[1] = max_remov;
                return (changes);
            }
    return (NULL);
}

int *finishing_artificial_play(int *board, int nb_line, int max_remov)
{
    int total = 0;

    for (; max_remov > 0; max_remov -= 1) {
        total = calc_nb_sticks(board, nb_line);
        if (total <= max_remov * 2)
            return (finish(board, nb_line, max_remov, total));
        else
            return (simple_artificial_play(board, nb_line, max_remov));
    }
    return (NULL);
}

int filled_nb_line(int *board, int nb_line)
{
    int filled_lines = 0;

    for (int i = 0; i < nb_line; i += 1)
        if (board[i] > 0)
            filled_lines += 1;
    return (filled_lines);
}

int *artificial_int_play(int *board, int nb_line, int max_remov)
{
    if (filled_nb_line(board, nb_line) > 2)
        return (simple_artificial_play(board, nb_line, max_remov));
    else
        return (finishing_artificial_play(board, nb_line, max_remov));


    return (0);
}