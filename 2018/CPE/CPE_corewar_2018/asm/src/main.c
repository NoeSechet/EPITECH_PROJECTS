/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** main.c
*/

#include "proto.h"

void my_memset(char *str, char c, int to)
{
    for (int i = 0; i <= to; i++) {
        str[i] = c;
    }
}

void correct_args(int ac, char **av)
{
    int n = 0;

    if (ac != 2) {
        exit(84);
    }
    n = my_strlen(av[1]);
    if (av[1][n - 1] != 's' && av[1][n - 2] != '.') {
        exit(84);
    }
}

data_t *init_data(char **av)
{
    data_t *D = malloc(sizeof(data_t));

    D->V_FILE = vector_new(1);
    D->V_LABEL = vector_new(1);
    D->IS_NAME = false;
    D->IS_COM = false;
    D->pos = 0;
    D->line = 0;
    my_memset(D->header.prog_name, '\0', PROG_NAME_LENGTH + 1);
    my_memset(D->header.comment, '\0', COMMENT_LENGTH + 1);
    D = get_data(av[1], D);
    if (D == NULL)
        exit (84);
    return (D);
}

int main(int ac, char **av)
{
    data_t *D = NULL;

    if (ac == 2 && str_ncomp(av[1], "-h", 2) == true)
        display_usage();
    correct_args(ac, av);
    D = init_data(av);
    write_instruction(D, av[1]);
    vector_free(D->V_FILE);
    vector_free(D->V_LABEL);
    free(D);
    return (0);
}