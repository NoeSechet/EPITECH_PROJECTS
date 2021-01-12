/*
** EPITECH PROJECT, 2019
** program_player_1.c
** File description:
** program_player_1.c
*/

#include "include/utils.h"
#include "include/status.h"

int program_1(char *pos_p1)
{
    int pid_player_2 = 0;
    char **map_player_1;
    char **map_player_2 = init_map();
    int winner = 0;

    if ((map_player_1 = create_map(pos_p1)) == NULL)
        return (84);

    pid_player_2 = is_connection();

    status = 0;

    while ((winner = win_conditions(map_player_1, map_player_2)) == 2) {
        print_maps(map_player_1, map_player_2);
        player_turn(map_player_2, pid_player_2);
        if ((winner = win_conditions(map_player_1, map_player_2)) != 2)
            return (winner);
        enemy_turn(map_player_1, pid_player_2);
    }
    return (winner);
}