/*
** EPITECH PROJECT, 2019
** program_player_2.c
** File description:
** program_player_2.c
*/

#include "include/utils.h"

int program_2(int pid_player_2, char *pos_p2)
{
    char **map_player_1;
    char **map_player_2 = init_map();
    int winner = 0;


    if (((map_player_1 = create_map(pos_p2)) == NULL) ||
            (kill(pid_player_2, SIGUSR2) == -1))
        return (84);

    my_printf("my_pid: %ld\n", getpid());
    my_printf("successfully connected\n");
    while ((winner = win_conditions(map_player_1, map_player_2)) == 2) {
        print_maps(map_player_1, map_player_2);
        enemy_turn(map_player_1, pid_player_2);
        if ((winner = win_conditions(map_player_1, map_player_2)) != 2)
            return (winner);
        player_turn(map_player_2, pid_player_2);
    }
    return (winner);
}