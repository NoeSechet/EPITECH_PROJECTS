/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** sem_col_present.c
*/

#include "utils_mini2.h"
#include "bin_tree.h"

int opera_present(char *input, char *opera)
{
    int opera_pos = my_strlen(input) - my_strlen(opera);

    for (; opera_pos >= 0; opera_pos -= 1) {
        if (comp_word(input + opera_pos, opera, my_strlen(opera)) == 1) {
            return (opera_pos);
        }
    }
    return (-1);
}