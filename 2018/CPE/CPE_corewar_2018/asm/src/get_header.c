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

void fill_name(data_t *data, char *txt)
{
    if (my_strlen(txt) > PROG_NAME_LENGTH || txt == NULL) {
        exit(84);
    }
    for (int i = 0; txt[i] != '\0'; i++) {
        data->header.prog_name[i] = txt[i];
    }
    data->IS_NAME = true;
    free(txt);
}

void fill_comment(data_t *data, char *txt)
{
    if (my_strlen(txt) > COMMENT_LENGTH || txt == NULL) {
        exit(84);
    }
    for (int i = 0; txt[i] != '\0'; i++) {
        data->header.comment[i] = txt[i];
    }
    data->IS_COM = true;
    free(txt);
}

void get_header(char **line, char *buffer, data_t *D)
{
    int nb_arg = 0;

    for (; line[nb_arg] != NULL; nb_arg++);
    if (nb_arg <= 0) {
        return;
    }
    for (int i = 0; line[i] != NULL; i++) {
        if (str_ncomp(line[i], ".name", 5) == true && line[i + 1] != NULL)
            fill_name(D, strcopy_spe(buffer, '"'));
        if (str_ncomp(line[i], ".comment", 8) == true && line[i + 1] != NULL)
            fill_comment(D, strcopy_spe(buffer, '"'));
    }
}