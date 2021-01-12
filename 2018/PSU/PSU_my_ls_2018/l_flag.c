/*
** EPITECH PROJECT, 2019
** l_flag.c
** File description:
** l_flag.c
*/

#include "utils.h"

void check_stat_info(char *file, struct dirent *dirread,
    struct stat *stat_info)
{
    if (file != NULL) {
        stat(fusion(fusion(file, "/"), dirread->d_name), stat_info);
    } else {
        stat(dirread->d_name, stat_info);
    }
}

void total_print(char *file, struct dirent *dirread)
{
    DIR *directory = NULL;
    struct stat stat_info;
    int total_block_size = 0;

    if (file != NULL) {
        directory = opendir(file);
    } else {
        directory = opendir(".");
    }
    while ((dirread = readdir(directory)) != NULL) {
        if (dirread->d_name[0] != '.') {
            check_stat_info(file, dirread, &stat_info);
            total_block_size += ((stat_info.st_blocks *
            (stat_info.st_blksize / 2)) / stat_info.st_blksize);
        }
    }
    closedir(directory);
    my_printf("total %d\n", total_block_size);
}

int open_readdir_once(struct dirent *dirread)
{
    DIR *path = opendir(".");
    if (path == NULL)
        return (-1);
    int max_nb_space = 0;
    int nb_space = 0;
    struct stat stat_info_test;

    while ((dirread = readdir(path)) != NULL) {
        if (dirread->d_name[0] != '.') {
            stat(dirread->d_name, &stat_info_test);
            nb_space = calc_nb_space(stat_info_test.st_size);
            if (max_nb_space < nb_space)
                max_nb_space = nb_space;
        }
    }
    closedir(path);
    return (max_nb_space);
}

void print_stat_info_readdir(struct stat stat_info, int max_nb_space,
struct dirent *dirread)
{
    type_protection_nb_link(stat_info);
    ownername_groupname(stat_info);
    size_in_octet(stat_info, max_nb_space);
    print_date(stat_info);
    file_name(dirread);
    my_putchar('\n');
}

void l_flag(char *file)
{
    struct dirent *dirread = NULL;
    DIR *directory = NULL;
    struct stat stat_info;
    int max_nb_space = 0;

    if (file != NULL && file[0] != '-')
        directory = opendir(file);
    else
        directory = opendir(".");
    if (l_error_function(directory, file, stat_info) == 1)
        return;
    total_print(file, dirread);
    max_nb_space = open_readdir_once(dirread);
    while ((dirread = readdir(directory)) != NULL) {
        check_stat_info(file, dirread, &stat_info);
        if (dirread->d_name[0] != '.')
            print_stat_info_readdir(stat_info, max_nb_space, dirread);
    }
}