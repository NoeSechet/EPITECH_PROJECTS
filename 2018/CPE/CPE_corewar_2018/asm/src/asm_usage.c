/*
** EPITECH PROJECT, 2019
** usage
** File description:
** usage
*/

#include "lib.h"
#include "utils.h"

void display_usage(void)
{
    FILE *fd = fopen("assets/usage.txt", "r");
    char *buffer = NULL;
    size_t n = 0;

    if (fd == NULL)
        return;
    while (getline(&buffer, &n, fd) >= 0) {
        write(1, buffer, my_strlen(buffer));
    }
    fclose(fd);
    free(buffer);
}