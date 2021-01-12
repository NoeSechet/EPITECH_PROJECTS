/*
** EPITECH PROJECT, 2019
** player_interactions.c
** File description:
** player_interactions.c
*/

#include "include/utils.h"

void alter_board(int *board, int chosen_line, int chosen_remov, int turn_count)
{
    board[chosen_line] -= chosen_remov;
    if (turn_count % 2 == 1)
        write(1, "Player removed ", 15);
    else
        write(1, "AI removed ", 11);
    my_put_nbr(chosen_remov);
    write(1, " match(es) from line ", 21);
    my_put_nbr(chosen_line + 1);
    write(1, "\n", 1);
}

int is_empty_board(int *board, int nb_line)
{
    int total = 0;

    for (int i = 0; i < nb_line; i += 1) {
        total += board[i];
    }
    if (total == 0)
        return (1);
    return (0);
}

int *check_errors(int *board, int nb_line, int max_remov)
{
    char *buf = NULL;
    size_t size = 0;
    int *changes = malloc(sizeof(int) * 2);
    changes[0] = 0;
    changes[1] = 0;

    write(1, "Line: ", 6);
    if (getline(&buf, &size, stdin) == -1)
        return (NULL);
    changes[0] = my_get_nbr(buf);
    if (check_line_errors(changes[0], nb_line) == 1)
        return (check_errors(board, nb_line, max_remov));
    write(1, "Matches: ", 9);
    if (getline(&buf, &size, stdin) == -1)
        return (NULL);
    changes[1] = my_get_nbr(buf);
    if (check_remov_errors(changes[1], board[changes[0] - 1], max_remov) == 1)
        return (check_errors(board, nb_line, max_remov));
    free(buf);
    return (changes);
}

int check_win(int turn_count)
{
    if (turn_count % 2 == 0) {
        write(1, "You lost, too bad...\n", 21);
        return (2);
    } else {
        write(1, "I lost... snif... but I'll get you next time!!\n", 47);
        return (1);
    }
}

int player_interaction(int *board, int nb_line, int max_remov)
{
    int *changes = NULL;
    int turn_count = 1;

    while (is_empty_board(board, nb_line) == 0) {
        if (turn_count % 2 == 1) {
            write(1, "Your turn:\n", 11);
            if ((changes = check_errors(board, nb_line, max_remov)) == NULL)
                return (0);
        } else {
            write(1, "AI's turn...\n", 13);
            changes = artificial_int_play(board, nb_line, max_remov);
        }
        alter_board(board, changes[0] - 1, changes[1], turn_count);
        print_board(board, nb_line);
        turn_count += 1;
    }
    return (check_win(turn_count));
}