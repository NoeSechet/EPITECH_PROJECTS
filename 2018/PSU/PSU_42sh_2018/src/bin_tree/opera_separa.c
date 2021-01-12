/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** opera_separa.c
*/

#include "lib.h"
#include "struct_tree.h"

char **opera_separa(char *input, char *opera)
{
    int opera_pos = 0;
    char **sem_col_branch = malloc(sizeof(char *) * 2);
    int i = 0;
    int j = 0;

    if ((opera_pos = detect_opera(input, opera)) <= 0) {
        return (NULL);
    }
    sem_col_branch[0] = malloc(sizeof(char) * opera_pos + 1);
    sem_col_branch[1] = malloc(sizeof(char) * (strlen(input) - opera_pos));
    for (; i < opera_pos; i += 1)
        sem_col_branch[0][i] = input[i];
    sem_col_branch[0][opera_pos] = '\0';
    i += strlen(opera);
    for (; input[i] != '\0'; i += 1, j += 1)
        sem_col_branch[1][j] = input[i];
    sem_col_branch[1][strlen(input) - opera_pos - 1] = '\0';
    return (sem_col_branch);
}