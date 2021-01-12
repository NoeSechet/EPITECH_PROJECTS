/*
** EPITECH PROJECT, 2018
** initiate_clone.c
** File description:
** initiate_clone
*/

#include "utils.h"

void check_length_lines(char *buf, int *lineLength, int *nbr_int)
{
    int i = 0;
    int counter = 0;

    while (i * (*lineLength) < *nbr_int) {
        while (buf[counter + i * (*lineLength + 1)] != '\n') {
            counter += 1;
        }
        if (counter != *lineLength)
            exit (84);
        counter = 0;
        i += 1;
    }
}

void charac_clone(char *buf, int *lineLength, int *nbr_int, int *line_nbr)
{
    int i = 0;

    while (buf[i] != '\n') {
        i += 1;
        *lineLength += 1;
    }
    *line_nbr = *nbr_int/(*lineLength);
    if (*lineLength == 1 || *line_nbr == 1) {
        single_point_square(buf);
    }
    check_length_lines(buf, lineLength, nbr_int);
}

int *initiate_clone(char *buf, int *nbr_int)
{
    int i = 0;
    int *clone = malloc(sizeof(int) * my_strlen(buf));

    while (buf[i] != '\0') {
        if (buf[i] == 'o') {
            clone[*nbr_int] = 0;
            *nbr_int += 1;
        }
        if (buf[i] == '.') {
            clone[*nbr_int] = 1;
            *nbr_int += 1;
        }
        if (!(buf[i] == 'o' || buf[i] == '.' || buf[i] == '\n')) {
            exit (84);
        }
        i += 1;
    }
    return (clone);
}