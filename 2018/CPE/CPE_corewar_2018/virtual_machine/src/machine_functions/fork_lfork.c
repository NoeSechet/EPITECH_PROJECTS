/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** fork_lfork.c
*/

#include "lib.h"
#include "utils.h"
#include "program.h"
#include "macros.h"

void copy_reg(int *reg, program_t *prog_copy)
{
    for (int i = 0; i < 16; i += 1) {
        prog_copy->reg[i] = reg[i];
    }
}

program_t *copy_prog(program_t *prog)
{
    program_t *prog_copy = malloc(sizeof(program_t));

    prog_copy->carry = prog->carry;
    prog_copy->header = prog->header;
    prog_copy->cycle = prog->cycle;
    prog_copy->is_living = prog->is_living;
    prog_copy->live = prog->live;
    prog_copy->memory = prog->memory;
    prog_copy->pc = prog->pc;
    prog_copy->is_fork = 1;
    copy_reg(prog->reg, prog_copy);
    prog_copy->size = prog->size;

    return (prog_copy);
}

void fork_core(corewar_t *corewar, program_t *prog)
{
    (void)corewar;
    program_t *prog_copy = NULL;
    int dir_value = 0;
    int pc = prog->pc;

    prog_copy = copy_prog(prog);
    arraylist_add(corewar->programs, (void *)prog_copy);
    read_size(prog, &dir_value, sizeof(short), 1);
    prog_copy->pc = check_mem_size((pc - 2 + dir_value % IDX_MOD));
}

void lfork_core(corewar_t *corewar, program_t *prog)
{
    (void)corewar;
    program_t *prog_copy = NULL;
    int dir_value = 0;
    int pc = prog->pc;

    prog_copy = copy_prog(prog);
    arraylist_add(corewar->programs, (void *)prog_copy);
    read_size(prog, &dir_value, sizeof(short), 1);
    prog_copy->pc = check_mem_size(pc - 2 + dir_value);
}