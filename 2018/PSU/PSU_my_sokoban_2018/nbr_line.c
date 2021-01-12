/*
** EPITECH PROJECT, 2018
** nbr_line.c
** File description:
** nbr_line
*/

#include "utils.h"

void unvalid_map_msg(void)
{
    write(0, "Unvalid map detected\n", 21);
    exit (84);
}

void calc_nbr_line(char *buf, player_t *player, layer_t *layer)
{
    layer->O_count = 0;
    layer->X_count = 0;

    for (int i = 0; buf[i] != '\0'; i += 1) {
        if (buf[i] == '\n')
            player->nbr_line += 1;
        if (buf[i] == 'O')
            layer->O_count += 1;
        if (buf[i] == 'X')
            layer->X_count += 1;
        if (buf[i] != '#' && buf[i] != 'O' && buf[i] != '\n' && buf[i]
                != 'X' && buf[i] != 'P' && buf[i] != ' ')
            unvalid_map_msg();
    }
    if (layer->O_count != layer->X_count)
        unvalid_map_msg();
    player->nbr_line += 1;
    free(buf);
}

void nbr_length_line(char *file, player_t *player, layer_t *layer)
{
    int fd = 0;
    char *buf = NULL;
    int read_value = 0;
    struct stat size_count;

    fd  = open(file, O_RDONLY);
    if (fd < 0)
        exit (84);
    stat(file, &size_count);
    buf = malloc (sizeof(char) * size_count.st_size + 1);
    read_value = read(fd, buf, size_count.st_size);
    buf[read_value] = '\0';
    calc_nbr_line(buf, player, layer);
}