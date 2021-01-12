/*
** EPITECH PROJECT, 2019
** argument
** File description:
** arg
*/

#include "proto.h"
#include "op.h"
#include "label.h"

void write_arg(char *line, int u, int fd, int i)
{
    int nbr = getnbr(line, u);
    short shr = 0;

    if (op_tab[i].NB_BYTE == 2) {
        shr = (short)nbr;
        swap_endian(&shr, 2);
        write(fd, &shr, 2);
    } else {
        swap_endian(&nbr, 4);
        write(fd, &nbr, 4);
    }
}

void write_register(char *line, int u, int fd, data_t *data)
{
    int nbr = getnbr(line, u);
    char c = 0;

    if (nbr > 16)
        exit (84);
    c = (char)nbr;
    write(fd, &c, 1);
    data->pos += 1;
}

void write_label(char *lab, data_t *data, int inf[3])
{
    label_t **tab = (label_t **)data->V_LABEL->array;
    int nbr = 0;
    short shr = 0;

    for (int a = 0; a < data->V_LABEL->nb_element; a++)
        if (my_strncmp(lab + inf[0], tab[a]->name, strlenght(tab[a]->name) - 1))
            nbr = tab[a]->byte;
    nbr -= data->line;
    if (op_tab[inf[2]].NB_BYTE == 2) {
        shr = nbr;
        swap_endian(&shr, 2);
        write(inf[1], &shr, 2);
    } else {
        swap_endian(&nbr, 4);
        write(inf[1], &nbr, 4);
    }
    data->pos += op_tab[inf[2]].NB_BYTE;
}

void instruction_arg(int i, char *line, int fd, data_t *data)
{
    int u = 0;

    for (int m = 0; m < op_tab[i].nbr_args; m++) {
        if (line[u] == DIRECT_CHAR)
            u++;
        if (line[u] == 'r')
            write_register(line, u + 1, fd, data);
        else if (line[u] == LABEL_CHAR)
            write_label(line, data, (int[3]){u + 1, fd, i});
        else {
            write_arg(line, u, fd, i);
            data->pos += op_tab[i].NB_BYTE;
        }
        for (; line[u] && line[u] != SEPARATOR_CHAR; u++);
        u++;
    }
}