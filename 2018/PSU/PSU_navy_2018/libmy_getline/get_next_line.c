/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** get_next_line.c
*/

#include "include/get_next_line.h"

int check_end_of_line(char *line, int index)
{
    (void)index;
    if (line == NULL)
        return (0);
    for (int i = 0; i < index ; i += 1) {
        if (line[i] == '\0')
            return (2);
        if (line[i] == '\n')
            return (1);
    }
    return (0);
}

char *concat(char *save, char *line, int multiplier, int index)
{
    int i = 0;
    int k = 0;
    char *new_str = NULL;

    if (save)
        for (; save[i] != '\0'; i += 1);
    new_str = malloc(sizeof(char) * (READ_SIZE * multiplier + i + 1));
    if (!new_str)
        return (NULL);
    if (save)
        for (; k < i; k += 1)
            new_str[k] = save[k];
    for (int l = 0; l < index; l += 1, k += 1)
        new_str[k] = line[l];
    new_str[k] = '\0';
    return (new_str);
}

char *remaining(char **line, int multiplier, int index)
{
    int k = 0;
    char *final_line = NULL;

    if (*line == NULL || *line[0] == '\0')
        return (NULL);
    final_line = malloc(sizeof(char) *
        (READ_SIZE * (multiplier - 1)) + index + 1);
    for (;*line[0] != '\0' && *line[0] != '\n'; k += 1, *line += 1)
        final_line[k] = *line[0];
    if (*line[0] != '\0' && *line[0] == '\n')
        *line += 1;
    final_line[k] = '\0';
    return (final_line);
}

char *get_next_line(int fd)
{
    static char *save = NULL;
    char *line = NULL;
    int multiplier = 1;
    int index = 0;

    while (1) {
        line = malloc(sizeof(char) * READ_SIZE + 1);
        if (line == NULL || fd < 0)
            return (NULL);
        if ((index = read(fd, line, READ_SIZE)) == 0)
            break;
        line[READ_SIZE] = '\0';
        save = concat(save, line, multiplier, index);
        if (check_end_of_line(line, index) != 0)
            break;
        multiplier += 1;
        free(line);
        line = NULL;
    }
    return (remaining(&save, multiplier, index));
}