/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** objd
*/

#ifndef OBJD_H_
#define OBJD_H_

#include <elf.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum Flag_e {
    NO_FLAG,
    S_FLAG,
    F_FLAG,
    F_S_FLAG
} Flag_e;

typedef struct elf_s {
    Elf64_Ehdr const *ehdr;
    Elf64_Shdr const *shdr;
    unsigned int len;
    void *end_file;
    char const *strtab;
    char const *filename;
} elf_t;

int launch_f_objd(int ac, int nbr_file, char **av);
int launch_s_objd(int ac, int nbr_file, char **av);
int launch_f_s_objd(int ac, int nbr_file, char **av);

int get_f_info(char *filename);
int get_s_info(char *filename);
int get_f_s_info(char *filename);

int check_elf_format(elf_t *elf);
int get_map(elf_t *elf, char *filename);

// -- PRINT ERROR -- //
int print_usage(void);
int print_flag_error(unsigned char wrong_flag);


#endif /* !OBJD_H_ */