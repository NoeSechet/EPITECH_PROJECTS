/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** sti.c
*/

#include "program.h"
#include "lib.h"
#include "utils.h"
#include "macros.h"

int get_arg_sti(program_t *prog, char param, int *arg_value)
{
    int reg_index = 0;
    int ind_value = 0;
    short short_value = 0;

    switch (param) {
        case 1: read_size(prog, &reg_index, sizeof(char), 1);
            if (reg_index > REG_NUMBER || reg_index < 1)
                return (0);
            *arg_value = prog->reg[reg_index - 1];
            break;
        case 2: read_size(prog, &short_value, sizeof(short), 1);
            *arg_value = short_value;
            break;
        case 3: read_size(prog, &ind_value, sizeof(short), 1);
            *arg_value = prog->memory[
                check_mem_size((prog->pc + ind_value % IDX_MOD))];
            break;
        default: return (0);
    }
    return (1);
}

void sti(corewar_t *corewar UNUSED, program_t *prog)
{
    unsigned char *params = check_coding_byte(prog);
    int reg_index = 0;
    int fir_index = 0;
    int sec_index = 0;
    int pc = prog->pc;

    if (params[0] != 1 || params[1] < 1 || params[1] > 3 ||
    (params[2] != DIRECT && params[2] != REGISTRY))
        return;
    read_size(prog, &reg_index, sizeof(char), 1);
    if (reg_index > REG_NUMBER || reg_index < 1)
        return;
    if (!get_arg_sti(prog, params[1], &fir_index) ||
        !get_arg_sti(prog, params[2], &sec_index))
            return;
    write_to_memory(prog, (int[2]){check_mem_size((pc +
        (fir_index + sec_index) % IDX_MOD - 2)), 1},
        &prog->reg[reg_index - 1], sizeof(int));
    free(params);
}