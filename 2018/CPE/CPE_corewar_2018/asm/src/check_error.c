/*
** EPITECH PROJECT, 2019
** error
** File description:
** error
*/

#include "lib.h"
#include "label.h"
#include "utils.h"
#include "op.h"

void check_error(char **array, data_t *data, int *byte)
{
    int fake;

    if (*byte != 0 && (data->IS_NAME == false || data->IS_COM == false))
        exit(84);
    if (*byte != 0 && (is_label(array[0]) == false
    && is_instruction(array[0], &fake) == false)) {
        exit(84);
    }
}