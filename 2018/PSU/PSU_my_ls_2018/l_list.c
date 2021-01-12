/*
** EPITECH PROJECT, 2019
** list.c
** File description:
** list
*/

#include "utils.h"

void type_protection_nb_link(struct stat stat_info)
{
    stat_info.st_mode & __S_IFDIR ? my_putchar('d') : my_putchar('-');
    stat_info.st_mode & S_IRUSR ? my_putchar('r') : my_putchar('-');
    stat_info.st_mode & S_IWUSR ? my_putchar('w') : my_putchar('-');
    stat_info.st_mode & S_IXUSR ? my_putchar('x') : my_putchar('-');
    stat_info.st_mode & S_IRGRP ? my_putchar('r') : my_putchar('-');
    stat_info.st_mode & S_IWGRP ? my_putchar('w') : my_putchar('-');
    stat_info.st_mode & S_IXGRP ? my_putchar('x') : my_putchar('-');
    stat_info.st_mode & S_IROTH ? my_putchar('r') : my_putchar('-');
    stat_info.st_mode & S_IWOTH ? my_putchar('w') : my_putchar('-');
    stat_info.st_mode & S_IXOTH ? my_putchar('x') : my_putchar('-');
    my_printf(" %ld ", stat_info.st_nlink);
}

void ownername_groupname(struct stat stat_info)
{
    struct passwd *owner_info = NULL;
    struct group *group_info = NULL;
    owner_info = getpwuid(stat_info.st_uid);
    group_info = getgrgid(stat_info.st_gid);

    my_printf("%s ", owner_info->pw_name);
    my_printf("%s ", group_info->gr_name);
}

void size_in_octet(struct stat stat_info, int max_nb_space)
{
    int nb_space = 0;
    int size = stat_info.st_size;
    int size_len = 0;

    if (size == 0)
        size_len = 1;
    else
        while (size != 0) {
            size /= 10;
            size_len += 1;
        }

    while (nb_space < ((max_nb_space) - size_len)) {
        my_putchar(' ');
        nb_space += 1;
    }
    my_printf("%ld ", stat_info.st_size);
}

void print_date(struct stat stat_info)
{
    char *time_test = ctime(&stat_info.st_mtime);
    char date[13];

    time_test += 4;
    for (int i = 0; time_test[i + 9] != '\0'; i += 1) {
        date[i] = time_test[i];
    }
    date[12] = '\0';
    my_printf("%s ", date);
}

void file_name(struct dirent *dirread)
{
    my_printf("%s", dirread->d_name);
}