/*
** EPITECH PROJECT, 2019
** format
** File description:
** format
*/

#include "lib.h"
#include "label.h"
#include "utils.h"
#include "op.h"

int get_nb_str_array(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return (i);
}

char *get_ins(char **line, int *size)
{
    char *op = strcopy(line[0]);

    if (op[0] == '#' || op[0] == '.')
        return (NULL);
    *size = my_strlen(op) + 1;
    if (is_label(op) == true && get_nb_str_array(line) >= 2) {
        free(op);
        op = cat(cat(line[0], " "), strcopy(line[1]));
        *size = my_strlen(op) + 1;
    }
    free_array(line);
    return (op);
}

char *format_line(char *buffer, int *byte)
{
    (void)*byte;
    int end_op = 0;
    char *op = get_ins(str_to_word_array(buffer, ' '), &end_op);
    char *param = NULL;
    char **array = str_to_word_array(buffer, ' ');

    if (op == NULL || array[0][0] == '.' || array[0][0] == '#') {
        return (strcopy(buffer));
    }
    param = strcopy_pos(buffer, end_op);
    param = str_clean(param, ' ', true);
    param = cat(cat(op, " "), param);
    free(op);
    return (param);
}