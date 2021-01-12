/*
** EPITECH PROJECT, 2019
** get
** File description:
** get
*/

#include "lib.h"
#include "label.h"
#include "utils.h"
#include "op.h"

int is_correct_line(char **buffer, label_t *LABEL)
{
    int nb_arg = 0;

    for (; buffer[nb_arg] != NULL; nb_arg++);
    if (my_strlen(buffer[0]) < 1 || nb_arg <= 0 ||
        buffer[0][0] == '.' || buffer[0][0] == '#') {
        free(LABEL);
        return (84);
    }
    return (0);
}

int get_dvalue(char **line)
{
    for (int j = 0; line[j] != NULL; j++) {
        for (int i = 0; op_tab[i].mnemonique != 0; i++) {
            if (str_ncomp(line[j], op_tab[i].mnemonique,
            my_strlen(op_tab[i].mnemonique)) == 1)
                return (op_tab[i].NB_BYTE);
        }
    }
    return (DIR_SIZE);
}

void add_cbyte(int *byte, char **line)
{
    for (int j = 0; line[j] != NULL; j++) {
        for (int i = 0; op_tab[i].mnemonique != 0; i++) {
            if (str_ncomp(line[j], op_tab[i].mnemonique,
            my_strlen(op_tab[i].mnemonique)) == 1 && op_tab[i].IS_CB == true)
                *byte += 1;
        }
    }
}

void get_label(data_t *D, char **buffer, int *byte)
{
    label_t *LABEL = malloc (sizeof(label_t));
    int dvalue = 0;

    if (is_correct_line(buffer, LABEL) == 84)
        return;
    dvalue = get_dvalue(buffer);
    for (int i = 0; buffer[i] != NULL; i++) {
        if (is_instruction(buffer[i], byte) == 1) {
            continue;
        }
        if (is_label(buffer[i]) == 1) {
            LABEL->name = strcopy(buffer[i]);
            LABEL->byte = *byte;
            vector_push(D->V_LABEL, (void *)LABEL);
            continue;
        }
        *byte = *byte + get_byte(buffer[i], dvalue);
    }
    add_cbyte(byte, buffer);
}
