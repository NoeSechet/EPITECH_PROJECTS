/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** init_functions.c
*/

#include "program.h"
#include "lib.h"

void init_prog_stats(program_t *prog, unsigned int option[3])
{
    prog->carry = 0;
    prog->cycle = -1;
    prog->live = 0;
    prog->is_living = 1;
    for (int i = 0; i < REG_NUMBER; i++)
        prog->reg[i] = 0;
    prog->reg[0] = option[1] ? option[1] : option[2];
    prog->is_fork = 0;
}