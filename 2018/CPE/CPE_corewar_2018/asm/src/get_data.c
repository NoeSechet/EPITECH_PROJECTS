/*
** EPITECH PROJECT, 2019
** get_data
** File description:
** get_data
*/

#include "lib.h"
#include "label.h"
#include "utils.h"
#include "op.h"

char **cat_ins_param(char *ar_1, char **ar_2, int s_2)
{
    int size = 1 + s_2;
    int i = 1;
    char **result = malloc(sizeof(char *) * (size + 1));

    result[0] = ar_1;
    for (int j = 0; ar_2[j] != NULL; i++, j++) {
        result[i] = ar_2[j];
    }
    result[size] = NULL;
    return (result);
}

int char_in_str(char *str, char c)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            nb += 1;
    }
    return (nb);
}

char **instruction_to_array(char *format_line)
{
    char **ins = str_to_word_array(format_line, ' ');
    int ins_s = get_nb_str_array(ins);
    char **param = NULL;
    int param_s = 0;
    char **array_r = NULL;

    if (ins[0][0] == '#' || ins[0][0] == '.' || ins_s < 2 ||
        (char_in_str(ins[1], SEPARATOR_CHAR) < 1)) {
        return (ins);
    }
    param = str_to_word_array(ins[1] , SEPARATOR_CHAR);
    param_s = get_nb_str_array(param);
    array_r = cat_ins_param(ins[0], param, param_s);
    return (array_r);
}

void loop_data(FILE *fd, data_t *D, int *byte)
{
    char **array = NULL;
    char *buffer = NULL;
    char *f_line = NULL;
    size_t n = 0;

    while (getline(&buffer, &n, fd) >= 0) {
        f_line = str_clean(format_line(buffer, byte), ' ', false);
        vector_push(D->V_FILE, (void *) strcopy(f_line));
        array = instruction_to_array(f_line);
        check_error(array, D, byte);
        get_header(array, buffer, D);
        get_label(D, array, byte);
        free(f_line);
        free_array(array);
    }
    free(buffer);
    fclose(fd);
}

data_t *get_data(char *path, data_t *D)
{
    FILE *fd = fopen(path, "r");
    int byte = 0;
    int magic = COREWAR_EXEC_MAGIC;

    if (fd == NULL)
        return (NULL);
    loop_data(fd, D, &byte);
    if (D->IS_NAME == false || D->IS_COM == false)
        return (NULL);
    swap_endian(&byte, sizeof(int));
    D->header.prog_size = byte;
    swap_endian(&magic, sizeof(int));
    D->header.magic = magic;
    return (D);
}