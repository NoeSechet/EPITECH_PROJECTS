/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** and_or_xor.c
*/

#include "utils.h"
#include "lib.h"
#include "program.h"
#include "macros.h"

int check_mem_size(int index_mem)
{
    return (MOD(index_mem, MEM_SIZE));
}

int get_arg_and_or_xor(program_t *prog, char param, int *arg_value)
{
    int reg_index = 0;
    int ind_value = 0;

    switch (param) {
        case REGISTRY: read_size(prog, &reg_index, sizeof(char), 1);
            if (reg_index > REG_NUMBER || reg_index < 1)
                return (0);
            *arg_value = prog->reg[reg_index - 1];
            break;
        case DIRECT: read_size(prog, arg_value, sizeof(int), 1);
            break;
        case INDIRECT: read_size(prog, &ind_value, sizeof(short), 1);
            *arg_value = prog->memory[
                check_mem_size((prog->pc + ind_value % IDX_MOD))
            ];
            break;
        default: return (0);
    }
    return (1);
}

void and(corewar_t *corewar, program_t *prog)
{
    (void)corewar;
    unsigned char *params = check_coding_byte(prog);
    int dest_reg = 0;
    int fir_arg = 0;
    int sec_arg = 0;

    prog->carry = 0;
    if (params[2] != 1)
        return;
    if (!get_arg_and_or_xor(prog, params[0], &fir_arg) ||
        !get_arg_and_or_xor(prog, params[1], &sec_arg))
            return;
    read_size(prog, &dest_reg, sizeof(char), 0);
    if (dest_reg > REG_NUMBER || dest_reg < 1)
        return;
    prog->reg[dest_reg - 1] = fir_arg & sec_arg;
    prog->carry = 1;
    free(params);
}

void or(corewar_t *corewar, program_t *prog)
{
    (void)corewar;
    unsigned char *params = check_coding_byte(prog);
    int dest_reg = 0;
    int fir_arg = 0;
    int sec_arg = 0;
    prog->carry = 0;

    if (params[2] != 1)
        return;
    if (!get_arg_and_or_xor(prog, params[0], &fir_arg) ||
        !get_arg_and_or_xor(prog, params[1], &sec_arg))
            return;
    read_size(prog, &dest_reg, sizeof(char), 0);
    if (dest_reg > REG_NUMBER || dest_reg < 1)
        return;
    prog->reg[dest_reg - 1] = fir_arg | sec_arg;
    prog->carry = 1;
    free(params);
}

void xor(corewar_t *corewar, program_t *prog)
{
    (void)corewar;
    unsigned char *params = check_coding_byte(prog);
    int dest_reg = 0;
    int fir_arg = 0;
    int sec_arg = 0;

    prog->carry = 0;
    if (params[2] != 1)
        return;
    if (!get_arg_and_or_xor(prog, params[0], &fir_arg) ||
        !get_arg_and_or_xor(prog, params[1], &sec_arg))
            return;
    read_size(prog, &dest_reg, sizeof(char), 0);
    if (dest_reg > REG_NUMBER || dest_reg < 1)
        return;
    prog->reg[dest_reg - 1] = fir_arg ^ sec_arg;
    prog->carry = 1;
    free(params);
}