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

int re_loop_get_byte(char *arg, int dvalue)
{
    char **array = str_to_word_array(arg, SEPARATOR_CHAR);
    int byte = 0;

    for (int i = 0; array[i] != NULL; i++) {
        byte = byte + get_byte(array[i], dvalue);
    }
    free_array(array);
    return (byte);
}

int get_byte(char *arg, int dvalue)
{
    int byte = 0;

    if (char_in_str(arg, SEPARATOR_CHAR) >= 1)
        return (re_loop_get_byte(arg, dvalue));
    if (is_label(arg) == true)
        return (0);
    switch (arg[0]) {
        case 'r':byte += 1; break;
        case '%':
        if (dvalue == DIR_SIZE) {
            byte += DIR_SIZE;
        } else {
            byte += 2;
        }
        break;
        default: byte += IND_SIZE; break;
    }
    return (byte);
}
