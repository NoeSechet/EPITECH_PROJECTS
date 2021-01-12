/*
** EPITECH PROJECT, 2019
** maze
** File description:
** maze
*/

#include "utils_dante.h"

char *get_file(char *file)
{
    char *buffer = NULL;
    int size = 0;
    int readsize = 0;
    int fd = 0;
    struct stat buf;

    stat(file, &buf);
    fd = open(file, O_RDONLY);
    if (fd < 0) exit (84);
    size = buf.st_size;
    if (size <= 0) exit (84);
    buffer = malloc(sizeof(char) * (size + 1));
    readsize = read(fd, buffer, size);
    buffer[readsize] = '\0';
    return (buffer);
}

char *get_maze(char *file_name)
{
    dijkstra(get_file(file_name));
    return (NULL);
}