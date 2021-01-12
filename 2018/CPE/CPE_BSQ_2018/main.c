/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include <utils.h>

char *read_file(char *file, coord_t *Sq_coords)
{
    int fd = 0;
    char *buf = NULL;
    int read_value = 0;
    struct stat size_count;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        exit (84);
    stat(file, &size_count);
    buf = malloc(sizeof(char) * size_count.st_size + 1);
    read_value = read(fd, buf, size_count.st_size);
    buf[read_value] = '\0';
    Sq_coords->size = size_count.st_size;
    return (buf);
}

int main(int ac, char **av)
{
    char *buf = NULL;
    int *clone;
    int lineLength = 0;
    int nbr_int = 0;
    int line_nbr = 0;
    int nbr_first_line = 0;
    coord_t Sq_coords[4];

    (ac != 2 ? exit (84) : 0);
    buf = read_file(av[1], Sq_coords);
    clean_buf(&buf, Sq_coords, &nbr_first_line);
    clone = initiate_clone(buf, &nbr_int);
    charac_clone(buf, &lineLength, &nbr_int, &line_nbr);
    (nbr_first_line != line_nbr ? exit (84) : 0);
    fill_struct(Sq_coords, clone);
    set_coord(&lineLength, &line_nbr, Sq_coords);
    final_square(buf, Sq_coords, lineLength);
    return (0);
}