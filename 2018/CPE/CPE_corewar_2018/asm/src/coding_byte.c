/*
** EPITECH PROJECT, 2019
** coding byte
** File description:
** coding_byte
*/

#include "lib.h"
#include "op.h"

void write_byte(char *byte, int len, int fd)
{
    char c = 0;
    int n = 128;

    for (int x = 0; x < len; x++) {
        if (byte[x] == '1')
            c += n;
        n /= 2;
    }
    write(fd, &c, 1);
}

void fill_byte(char *byte, char *line, int len, int i)
{
    int u = 0;
    int l = 0;

    for (; l < len; l++)
        byte[l] = '0';
    for (int j = 0; j < op_tab[i].nbr_args * 2; j += 2) {
        if (line[u] == 'r') {
            byte[j] = '0';
            byte[j + 1] = '1';
        } else if (line[u] == DIRECT_CHAR) {
            byte[j] = '1';
            byte[j + 1] = '0';
        } else {
            byte[j] = '1';
            byte[j + 1] = '1';
        }
        for (; line[u] && line[u] != SEPARATOR_CHAR; u++);
        u++;
    }
}

void coding_byte(int i, char *line, int fd)
{
    int len = (op_tab[i].nbr_args * 2) % 4 == 0 ? op_tab[i].nbr_args * 2 :
        op_tab[i].nbr_args * 2 + 2;
    len = len % 8 == 0 ? len : len + 4;
    char *byte = malloc(sizeof(char) * len);

    fill_byte(byte, line, len, i);
    write_byte(byte, len, fd);
    free(byte);
}