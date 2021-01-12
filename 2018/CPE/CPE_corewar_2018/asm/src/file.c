/*
** EPITECH PROJECT, 2019
** file
** File description:
** file
*/

#include "proto.h"
#include "op.h"

int create_file(char const *file, char **new)
{
    int fd = 0;
    int len = strlenght(file);

    if (file[len - 1] == 's' && file[len - 2] == '.')
        *new = copycat(file, ".cor", len - 2);
    else
        *new = copycat(file, ".cor", len);
    fd = open(*new, O_CREAT, 00666);
    close (fd);
    fd = open(*new, O_WRONLY | O_TRUNC);
    return (fd);
}

void cmp_loop(char **line, int y, int fd, data_t *data)
{
    for (int i = 0; i < 16; i++) {
        if (my_strcmp(line[y], op_tab[i].mnemonique)) {
            data->line = data->pos;
            write(fd, &op_tab[i].code, 1);
            data->pos += 1;
            if (op_tab[i].IS_CB) {
                coding_byte(i, line[y + 1], fd);
                data->pos += 1;
            }
            instruction_arg(i, line[y + 1], fd, data);
        }
    }
}

void print_header(data_t *data, int fd, char *new)
{
    char *buf[data->pos + 1];
    for (int t = 0; t < data->pos; t++)
        buf[t] = 0;
    close(fd);
    fd = open(new, O_RDONLY);
    read(fd, buf, data->pos);
    close(fd);
    data->header.prog_size = data->pos;
    swap_endian(&data->header.prog_size, 4);
    fd = open(new, O_WRONLY | O_TRUNC);
    write(fd, &data->header, sizeof(header_t));
    write(fd, buf, data->pos);
    free(new);
    close (fd);
}

void write_instruction(data_t *data, char *file)
{
    char *new = NULL;
    int fd = create_file(file, &new);
    int h = 0;
    char **line = NULL;

    while (h < data->V_FILE->nb_element) {
        line = str_to_word_array((char *)data->V_FILE->array[h], ' ');
        for (int y = 0; line[y]; y++)
            cmp_loop(line, y, fd, data);
        free_array(line);
        h++;
    }
    print_header(data, fd, new);
}