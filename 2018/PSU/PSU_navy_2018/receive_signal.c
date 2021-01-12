/*
** EPITECH PROJECT, 2019
** receive_signal
** File description:
** receive_signal
*/

#include "include/utils.h"
#include "include/status.h"

void sig_receive(int sig, siginfo_t *info, void *context)
{
    (void)info;
    (void)context;

    if (sig == SIGUSR1)
        status = 1;
    else
        status = 0;
}

int receive_signal(void)
{
    int bomb_pos_dec = 0;
    char *bomb_pos_bin = strcopy("");
    struct sigaction sig;

    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = &sig_receive;

    my_printf("\nwaiting for enemy's attack...\n");

    for (int i = 0; i < 8; i++) {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        pause();
        if (status == 1)
            bomb_pos_bin = fusion(bomb_pos_bin, "1");
        else
            bomb_pos_bin = fusion(bomb_pos_bin, "0");
    }
    bomb_pos_dec = bin_into_deci(bomb_pos_bin);
    return (bomb_pos_dec);
}