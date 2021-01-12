/*
** EPITECH PROJECT, 2019
** utils.h
** File description:
** utils.h
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char **print_game_board(int line_nbr);
int my_get_nbr(char const *str);
void my_put_nbr(int nb);

int *fill_board(int nb_line);
void print_board(int *board, int nb_line);

int player_interaction(int *board, int nb_line, int max_remov);
int check_line_errors(int chosen_line, int nb_line);
int check_remov_errors(int chosen_remov, int nb_sticks, int max_remov);
int *artificial_int_play(int *board, int nb_line, int max_remov);
int *simple_artificial_play(int *board, int nb_line, int max_remov);
int *finish(int *board, int nb_line, int max_remov, int total);

#endif /* !UTILS_H_ */