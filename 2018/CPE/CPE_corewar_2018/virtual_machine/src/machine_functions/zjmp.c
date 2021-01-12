/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** zjmp.c
*/

#include "lib.h"
#include "utils.h"
#include "program.h"
#include "macros.h"

void zjmp(corewar_t *corewar UNUSED, program_t *prog)
{
    short fir_arg = 0;
    int pc = prog->pc - 1;

    read_size(prog, &fir_arg, sizeof(short), 1);
    if (prog->carry == 0) return;
    prog->pc = check_mem_size((pc + fir_arg % IDX_MOD));
}