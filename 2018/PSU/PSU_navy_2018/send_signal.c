/*
** EPITECH PROJECT, 2019
** send_signal.c
** File description:
** send_signal.c
*/

#include "include/utils.h"

int send_signal(int bomb_pos, int pid_player_2)
{
    struct timespec sleep_struct;
    sleep_struct.tv_sec = 0;
    sleep_struct.tv_nsec = 100000;
    char *bomb_pos_bin = deci_into_bin(bomb_pos);

    for (int i = 0; bomb_pos_bin[i] != '\0'; i += 1) {
        if (bomb_pos_bin[i] == '1') {
            kill(pid_player_2, SIGUSR1);
        } else if (bomb_pos_bin[i] == '0') {
            kill(pid_player_2, SIGUSR2);
        }
        nanosleep(&sleep_struct, NULL);
    }
    return (1);
}