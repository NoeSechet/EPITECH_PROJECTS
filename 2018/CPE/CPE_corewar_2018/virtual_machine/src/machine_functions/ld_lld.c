/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** ld_lld.c
*/

#include "program.h"
#include "utils.h"
#include "macros.h"

int get_arg_ld(program_t *prog, char param, char index_lld)
{
    int ind_value = 0;
    int arg_value = 0;

    switch (param) {
        case 2: read_size(prog, &arg_value, sizeof(int), 1);
            break;
        case 3: read_size(prog, &ind_value, sizeof(short), 1);
            arg_value = prog->memory[
                check_mem_size(index_lld ? prog->pc + ind_value :
                (prog->pc + ind_value % IDX_MOD))
            ];
            break;
        default: break;
    }
    return (arg_value);
}

void ld(corewar_t *corewar UNUSED, program_t *prog)
{
    unsigned char *params = check_coding_byte(prog);
    unsigned char reg_value = 0;
    int value = 0;

    prog->carry = 0;
    if (params[0] == 1 || params[1] != 1)
        return;
    value = get_arg_ld(prog, params[0], 0);
    read_size(prog, &reg_value, sizeof(unsigned char), 0);
    if (reg_value > REG_NUMBER || reg_value < 1)
        return;
    prog->reg[reg_value - 1] = value;
    prog->carry = 1;
    free(params);
}

void lld(corewar_t *corewar UNUSED, program_t *prog)
{
    unsigned char *params = check_coding_byte(prog);
    char reg_value = 0;
    int value = 0;

    prog->carry = 0;
    if (params[0] == 1 || params[1] != 1)
        return;
    value = get_arg_ld(prog, params[0], 1);
    read_size(prog, &reg_value, sizeof(char), 1);
    prog->reg[reg_value - 1] = value;
    prog->carry = 1;
    free(params);
}