/*
** EPITECH PROJECT, 2019
** is_connection.c
** File description:
** is_connection.c
*/

#include "include/utils.h"
#include "include/status.h"

void sig_info(int sig, siginfo_t *info, void *context)
{
    (void)sig;
    (void)context;

    status = info->si_pid;
}

int is_connection(void)
{
    struct sigaction sig;

    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = &sig_info;
    sigaction(SIGUSR2, &sig, NULL);

    my_printf("my_pid: %ld\n", getpid());
    my_printf("waiting for enemy connection...\n\n");
    pause();

    my_printf("enemy connected\n");

    return (status);
}