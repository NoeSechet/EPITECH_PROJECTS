/*
** EPITECH PROJECT, 2019
** finishing_artificial_play.c
** File description:
** finishing_artificial_play.c
*/

#include "include/utils.h"

int *finish(int *board, int nb_line, int max_remov, int total)
{
    int *changes = malloc(sizeof(int) * 2);

    if (nb_line == 1 && total == max_remov + 1) {
        for (int i = 0; i < nb_line; i += 1)
            if (board[i] > 0) {
                changes[0] = i;
                changes[1] = max_remov;
            }
    } else if (nb_line == 1 && total < max_remov) {
        for (int i = 0; i < nb_line; i += 1)
            if (board[i] > 0) {
                changes[0] = i;
                changes[1] = total - 1;
            }
    } else
        return (simple_artificial_play(board, nb_line, max_remov));
    return (changes);
}