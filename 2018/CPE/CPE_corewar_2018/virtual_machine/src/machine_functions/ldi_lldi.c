/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** ldi_lldi.c
*/

#include "lib.h"
#include "program.h"
#include "utils.h"
#include "macros.h"

int get_arg_ldi(program_t *prog, char param, char index_lldi, int *arg_value)
{
    int reg_index = 0;
    int ind_value = 0;
    short short_val = 0;

    switch (param) {
        case 1: read_size(prog, &reg_index, sizeof(char), 1);
            if (reg_index > REG_NUMBER || reg_index < 1)
                return (0);
            *arg_value = prog->reg[reg_index - 1];
            break;
        case 2: read_size(prog, &short_val, sizeof(short), 1);
            *arg_value = short_val;
            break;
        case 3: read_size(prog, &ind_value, sizeof(short), 1);
            *arg_value = prog->memory[check_mem_size(index_lldi == 1 ?
            prog->pc + ind_value : (prog->pc + ind_value % IDX_MOD))];
                break;
        default: return (0);
    }
    return (1);
}

void ldi(corewar_t *corewar UNUSED, program_t *prog)
{
    unsigned char *params = check_coding_byte(prog);
    char reg_index = 0;
    int fir_param = 0;
    int sec_param = 0;
    int SUM = 0;
    int pc = prog->pc;

    prog->carry = 0;
    if (params[0] > 3 || params[0] == 0 ||
    params[1] == 3 || params[2] != 1)
        return;
    if (!get_arg_ldi(prog, params[0], 0, &fir_param) ||
        !get_arg_ldi(prog, params[1], 0, &sec_param))
            return;
    read_size(prog, &reg_index, sizeof(char), 1);
    if (reg_index > REG_NUMBER || reg_index < 1)
        return;
    SUM = *((int *)&prog->memory[
        check_mem_size(pc + (fir_param + sec_param) % IDX_MOD - 2)]);
    prog->reg[reg_index - 1] = SUM;
    prog->carry = 1;
    free(params);
}

void lldi(corewar_t *corewar UNUSED, program_t *prog)
{
    unsigned char *params = check_coding_byte(prog);
    char reg_index = 0;
    int fir_param = 0;
    int sec_param = 0;
    int SUM = 0;
    int pc = prog->pc;

    prog->carry = 0;
    if (params[0] > 3 || params[0] == 0 ||
    params[1] == 3 || params[2] != 1)
        return;
    if (!get_arg_ldi(prog, params[0], 1, &fir_param) ||
        !get_arg_ldi(prog, params[1], 1, &sec_param))
            return;
    read_size(prog, &reg_index, sizeof(char), 1);
    if (reg_index > REG_NUMBER || reg_index < 1)
        return;
    SUM = prog->memory[
        check_mem_size(pc - 2 + fir_param + sec_param)];
    prog->reg[reg_index - 1] = SUM;
    prog->carry = 1;
    free(params);
}