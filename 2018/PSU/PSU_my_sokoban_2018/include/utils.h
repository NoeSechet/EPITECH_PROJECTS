/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** utils
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>
#include "player_struct.h"

#ifndef UTILS_H
#define UTILS_H

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char *);
int my_strncmp(char const *s1, char const *s2, int n);
void instructions(char **av);
player_t *fill_player_struct(void);
layer_t *fill_layer_struct(player_t *player);
void fill_layer(char *line, layer_t *layer, int s);
void fill_player_pos(layer_t *layer, player_t *player);
void detect_o_pos(layer_t *layer);
void detect_x_pos(layer_t *layer);
void nbr_length_line(char *file, player_t *player, layer_t *layer);
void print_map(char **map);
void print_sky(char **sky);
void display_message(void);

void moves_up(layer_t *layer, player_t *player);
void moves_down(layer_t *layer, player_t *player);
void moves_right(layer_t *layer, player_t *player);
void moves_left(layer_t *layer, player_t *player);
void reset_map(layer_t *layer, player_t *player);
void win_lose_cond(layer_t *layer);

#endif