/*
** EPITECH PROJECT, 2018
** clean_buf.c
** File description:
** clean_buf
*/

#include "utils.h"

void show_num(char const *buf, int *nbr, int i)
{
    while (buf[i] >= '0' && buf[i] <= '9') {
        *nbr = *nbr * 10 + (buf[i] - '0');
        i++;
    }
}

int get_nbr_first_line(char const *buf)
{
    int i = 0;
    int nbr = 0;

    if ((buf[i] == '\0') || (!(buf[i] >= '0' && buf[i] <= '9') &&
        (buf[i] != '-' && buf[i] != '+')))
        exit (84);
    if (buf[i] == '-')
        nbr = nbr * -1;
    show_num(buf, &nbr, i);
    return (nbr);
}

char start_shift(char **buf)
{
    char start = (*buf)[0];

    *buf = *buf + 1;
    return (start);
}

void clean_buf(char **buf, coord_t *Sq_coords, int *nbr_first_line)
{
    *nbr_first_line = get_nbr_first_line(*buf);
    while ((*buf)[0] != '\n') {
        start_shift(buf);
        Sq_coords->size -= 1;
    }
    start_shift(buf);
    Sq_coords->size -= 1;
}