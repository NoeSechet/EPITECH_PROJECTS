/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** st.c
*/

#include "lib.h"
#include "program.h"
#include "utils.h"
#include "macros.h"

void copy_reg_value(program_t *prog, char param, int reg_value, int pc)
{
    int reg_index = 0;
    int arg_index = 0;

    if (param == REGISTRY) {
        read_size(prog, &reg_index, sizeof(char), 1);
        if (reg_value > REG_NUMBER || reg_value < 1)
            return;
        prog->reg[reg_index - 1] = reg_value;
    } else if (param == INDIRECT) {
        read_size(prog, &arg_index, sizeof(short), 1);
        write_to_memory(prog, (int[2]){
            check_mem_size((pc + arg_index % IDX_MOD - 2)), 1},
            &reg_value, sizeof(int));
    }
}

void st(corewar_t *corewar, program_t *prog)
{
    (void)corewar;
    unsigned char *params = check_coding_byte(prog);
    int reg = 0;
    int reg_value = 0;
    int pc = prog->pc;

    if (params[0] != 1 || params[1] == 2)
        return;
    read_size(prog, &reg, sizeof(char), 0);
    if (reg > REG_NUMBER || reg < 1)
        return;
    reg_value = prog->reg[reg - 1];
    copy_reg_value(prog, params[1], reg_value, pc);
    free(params);
}