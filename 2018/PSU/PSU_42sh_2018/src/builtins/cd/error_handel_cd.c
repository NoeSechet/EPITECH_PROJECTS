/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** handel error
*/

#include "mysh.h"

int gest_error(char *buf, int ret)
{
    struct stat st;

    if (!buf || ret == 0)
        return (0);
    lstat(buf, &st);
    if (!access(buf, F_OK) && S_ISDIR(st.st_mode)) {
        my_printf("%s: Permission denied.\n", buf);
        return (1);
    } else if (!access(buf, F_OK) && !S_ISDIR(st.st_mode)) {
        my_printf("%s: Not a directory.\n", buf);
        return (1);
    } else {
        if (buf[0] == '-')
            my_printf(": No such file or directory.\n");
        else
            my_printf("%s: No such file or directory.\n", buf);
        return (1);
    }
    return (0);
}
