/*
** EPITECH PROJECT, 2019
** utils.h
** File description:
** utils.h
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_getnbr (char const *str);
int my_strlen(char const *str);
char *strcopy(char *str);

void my_printf(char *s, ...);
char *get_next_line(int fd);
int my_strlen(char const *str);
int str_n_comp(char const *s1, char const *s2, int length);
char *fusion(char *dest, char *src);

int is_description(char *str);

char **create_map(char *script_file);
char **init_map(void);

int is_connection(void);

void print_maps(char **map_player, char **map_enemy);

int program_1(char *pos_p1);

int program_2(int pid_player_2, char *pos_p2);

int check_error(char *line);
int check_boat_presence(char **map);
int is_right_letter(char c);
int is_right_nbr(char n);

int player_turn(char **map_player_2, int pid_player_2);

char *deci_into_bin(int decimal_nbr);
int bin_into_deci(char *binary_nbr);

int win_conditions(char **map_player_1, char **map_player_2);

int send_signal(int bomb_pos, int pid_player_2);

int hit_or_missed(int bomb_pos, char **map_player_2);
void change_map(int bomb_pos, char **map, char c);

int receive_signal(void);

int enemy_turn(char **map_player_1, int pid_player_2);

char *convert_int_into_pos(int pos);

#endif