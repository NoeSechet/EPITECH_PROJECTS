/*
** EPITECH PROJECT, 2019
** l_error_function.c
** File description:
** l_error_function.c
*/

#include "utils.h"

int l_error_function(DIR *directory, char *file, struct stat stat_info)
{
    if (directory == NULL) {
        if (errno == ENOTDIR) {
            simple_l_flag(file, stat_info);
            return (1);
        }
        perror(file);
        return (1);
    }
    return (0);
}