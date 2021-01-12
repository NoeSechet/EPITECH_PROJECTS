/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** print_usage
*/

#include "objd.h"

int print_usage(void)
{
    FILE *fptr = NULL;
    char c = 0;

    if ((fptr = fopen("./objdump_dir/usage.txt", "r")) == NULL)
        return 0;
    while ((c = fgetc(fptr)) != EOF)
        fprintf(stderr, "%c", c);
    fclose(fptr);
    return 0;
}