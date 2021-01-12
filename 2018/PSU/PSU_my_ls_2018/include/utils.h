/*
** EPITECH PROJECT, 2019
** utils.h
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <sys/types.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <errno.h>
#include "flag.h"

void my_printf(char *s, ...);
int *my_pushswap(int ac, char **av);
void my_putchar(char c);
char *fusion(char *dest, char *src);
int calc_nb_space(int size);

flag_t *init_flag_struct(void);
void fill_flag_struct(int ac, char **av, flag_t *flag, int *i);

int check_flag_presence(int ac, char **av);
int check_file_presence(int ac, char **av);

void check_flag_struct(char **av, flag_t *flag, int i);
void l_flag(char *file);
void simple_l_flag(char *file, struct stat stat_info);
int l_error_function(DIR *directory, char *file, struct stat stat_info);
void d_flag(char *file);
void t_flag(char *file);

int open_readdir_once(struct dirent *dirread);
void total_print(char *file, struct dirent *dirread);
void check_stat_info(char *file, struct dirent *dirread,
struct stat *stat_info);

void type_protection_nb_link(struct stat stat_info);
void ownername_groupname(struct stat stat_info);
void size_in_octet(struct stat stat_info, int max_nb_space);
void print_date(struct stat stat_info);
void file_name(struct dirent *dirread);

#endif /* !UTILS_H_ */