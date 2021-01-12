/*
** EPITECH PROJECT, 2019
** enemy_turn
** File description:
** enemy_turn
*/

#include "include/utils.h"

int is_boat_hit(char **map, int bomb_pos)
{
    for (int i = 2; map[i] != NULL; i++) {
        for (int j = 2; map[i][j] != '\0'; j++, bomb_pos -= 1) {
            if (map[i][j] == ' ')
                j += 1;
            if (bomb_pos == 1 && (is_right_nbr(map[i][j]) == 1))
                return (1);
        }
    }
    return (0);
}

int enemy_turn(char **map_player_1, int pid_player_2)
{
    struct timespec sleep_struct;
    sleep_struct.tv_sec = 0;
    sleep_struct.tv_nsec = 100000;
    int bomb_pos_dec = receive_signal();

    nanosleep(&sleep_struct, NULL);

    if (is_boat_hit(map_player_1, bomb_pos_dec) == 1) {
        my_printf("%s: hit\n", convert_int_into_pos(bomb_pos_dec));
        change_map(bomb_pos_dec, map_player_1, 'x');
        kill(pid_player_2, SIGUSR1);
    } else {
        my_printf("%s: missed\n", convert_int_into_pos(bomb_pos_dec));
        change_map(bomb_pos_dec, map_player_1, 'o');
        kill(pid_player_2, SIGUSR2);
    }
    nanosleep(&sleep_struct, NULL);
    return (0);
}