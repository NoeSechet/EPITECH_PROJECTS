/*
** EPITECH PROJECT, 2019
** hit_or_missed.c
** File description:
** hit_or_missed.c
*/

#include "include/utils.h"
#include "include/status.h"

void change_map(int bomb_pos, char **map, char c)
{
    for (int i = 2; map[i] != NULL; i += 1) {
        for (int j = 2; map[i][j] != '\0'; j++, bomb_pos -= 1) {
            if (map[i][j] == ' ')
                j += 1;
            if (bomb_pos == 1 && map[i][j] != 'x') {
                map[i][j] = c;
            }
        }
    }
}

void sig_check_hit_or_miss(int sig, siginfo_t *info, void *context)
{
    (void)info;
    (void)context;

    if (sig == SIGUSR1)
        status = 2;
    else
        status = 3;
}

int hit_or_missed(int bomb_pos, char **map_player_2)
{
    struct sigaction sig;

    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = &sig_check_hit_or_miss;

    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);

    pause();
    if (status == 2) {
        change_map(bomb_pos, map_player_2, 'x');
        my_printf("hit\n");
    } else if (status == 3) {
        change_map(bomb_pos, map_player_2, 'o');
        my_printf("missed\n");
    }
    return (1);
}