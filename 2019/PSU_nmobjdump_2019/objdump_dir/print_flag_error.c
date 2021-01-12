/*
** EPITECH PROJECT, 2020
** print_flag_error
** File description:
** print_flag_error
*/

#include "objd.h"

int print_flag_error(unsigned char wrong_flag)
{
    FILE *fptr1 = NULL;
    FILE *fptr2 = NULL;
    char c = 0;

    fprintf(stderr, "objdump: invalid option -- '%c'\n", wrong_flag);
    if ((fptr1 = fopen("./objdump_dir/usage.txt", "r")) == NULL) return 0;
    if ((fptr2 = fopen("./objdump_dir/flag_error.txt", "r")) == NULL) return 0;
    while ((c = fgetc(fptr1)) != EOF)
        fprintf(stderr, "%c", c);
    fprintf(stderr, "\n\n");
    fclose(fptr1);
    while ((c = fgetc(fptr2)) != EOF)
        fprintf(stderr, "%c", c);
    fprintf(stderr, "\n");
    fclose(fptr2);
    return 0;
}