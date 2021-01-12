/*
** EPITECH PROJECT, 2019
** get
** File description:
** get
*/

#include "utils_dante.h"

int get_width(char * maze)
{
    int it = 0;

    for (; maze[it] != '\n'; it++);
    return (it);
}

int get_height(char *maze)
{
    int height = 0;

    for (int it = 0; maze[it] != '\0'; it++) {
        if (maze[it] == '\n' && maze[it + 1] == '\0')
            height += 1;
        else if (maze[it + 1] == '\0')
            height += 1;
        else if (maze[it] == '\n')
            height += 1;
    }
    return (height);
}