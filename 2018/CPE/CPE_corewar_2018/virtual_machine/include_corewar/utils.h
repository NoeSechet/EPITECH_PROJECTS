/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

#include "lib.h"
#include "program.h"

int my_strlen(char const *str);
void my_put_nbr_base(int nb, char *base);
int is_number(char *str);
int my_get_nbr(char const *str);
int comp_word(char const *s1, char const *s2, int length);

char *get_prog_name(char *file_path);
void read_size(program_t *prog, void *obj, size_t size, int revert);
unsigned char *check_coding_byte(program_t *prog);
int get_params(program_t *program, int num, int *obj, int address_size);
void write_to_memory(program_t *program, int address[2],
    void *obj, size_t size);
int check_end(corewar_t *corewar);
void check_living(corewar_t *corewar);
int check_mem_size(int index_mem);
void print_mem(unsigned char *corewar, int address);

#endif /* !utils */
