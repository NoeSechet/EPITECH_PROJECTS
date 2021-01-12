/*
** EPITECH PROJECT, 2019
** my_ls.c
** File description:
** my_ls.c
*/

#include "utils.h"

int simple_ls(void)
{
    struct dirent *dirread = NULL;
    DIR *path = opendir(".");

    if (!path)
        return (84);

    while ((dirread = readdir(path)) != NULL)
        if (dirread->d_name[0] != '.') {
            my_printf("%s\n", dirread->d_name);
        }
    return (0);
}

int no_flag_with_path(char *file)
{
    struct dirent *dirread = NULL;
    DIR *directory = NULL;

    if (file != NULL)
        directory = opendir(file);
    else
        directory = opendir(".");
    if (directory == NULL) {
        if (errno == ENOTDIR) {
            my_printf("%s\n", file);
            return (0);
        }
        perror(file);
        return (0);
    }
    while ((dirread = readdir(directory)) != NULL)
        if (dirread->d_name[0] != '.')
            my_printf("%s\n", dirread->d_name);
    return (0);
}

int main(int ac, char **av)
{
    flag_t *flag = init_flag_struct();
    int i = 1;

    fill_flag_struct(ac, av, flag, &i);
    if (ac == 1) {
        simple_ls();
        return (0);
    }
    if (ac > 1 && (check_flag_presence(ac, av) == 0)) {
        no_flag_with_path(av[i]);
        return (0);
    }
    if (ac > 1) {
        check_flag_struct(av, flag, i);
    }
    return (0);
}