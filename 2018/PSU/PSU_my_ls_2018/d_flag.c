/*
** EPITECH PROJECT, 2019
** d_flag.c
** File description:
** d_flag.c
*/

#include "utils.h"

void d_flag(char *file)
{
    DIR *directory = NULL;

    if (file != NULL && file[0] != '-') {
        directory = opendir(file);
        if (directory != NULL)
            my_printf("%s\n", file);
        else {
            if (errno == ENOTDIR)
                my_printf("%s\n", file);
            else {
                perror(file);
                return;
            }
        }
    } else {
        my_printf(".\n");
    }
}