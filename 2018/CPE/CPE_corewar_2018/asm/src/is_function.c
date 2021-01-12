/*
** EPITECH PROJECT, 2019
** is
** File description:
** is
*/

#include "lib.h"
#include "label.h"
#include "utils.h"
#include "op.h"

int is_label_chars(char c)
{
    for (int i = 0; LABEL_CHARS[i] != '\0'; i++) {
        if (c == LABEL_CHARS[i])
            return (true);
    }
    return (false);
}

int is_instruction(char *arg, int *byte)
{
    for (int j = 0; op_tab[j].mnemonique != 0; j++) {
        if (str_ncomp(arg, op_tab[j].mnemonique,
            my_strlen(op_tab[j].mnemonique)) == true) {
            *byte += 1;
            return (true);
        }
    }
    return (false);
}

int is_label(char *line)
{
    int size = my_strlen(line);

    if (size <= 1)
        return (false);
    size -= 1;
    for (int i = 0; i < size; i++) {
        if (is_label_chars(line[i]) == false)
            return (false);
    }
    if (line[size] != LABEL_CHAR) {
        return (false);
    }
    return (true);
}