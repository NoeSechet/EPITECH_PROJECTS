/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** add_sub.c
*/

#include "lib.h"
#include "program.h"
#include "utils.h"
#include "macros.h"

void add(corewar_t *corewar UNUSED, program_t *prog)
{
    unsigned char *params = check_coding_byte(prog);
    int reg1 = 0;
    int reg2 = 0;
    int reg3 = 0;

    prog->carry = 0;
    if (params[0] != REGISTRY || params[1] != REGISTRY ||
    params[2] != REGISTRY)
        return;
    read_size(prog, &reg1, sizeof(char), 0);
    read_size(prog, &reg2, sizeof(char), 0);
    read_size(prog, &reg3, sizeof(char), 0);
    if (reg1 > REG_NUMBER || reg1 < 1 || reg2 > REG_NUMBER ||
    reg2 < 1 || reg3 > REG_NUMBER || reg3 < 1)
        return;
    prog->reg[reg3 - 1] = prog->reg[reg1 - 1] + prog->reg[reg2 - 1];
    prog->carry = 1;
    free(params);
}

void sub(corewar_t *corewar UNUSED, program_t *prog)
{
    unsigned char *params = check_coding_byte(prog);
    int reg1 = 0;
    int reg2 = 0;
    int reg3 = 0;

    prog->carry = 0;
    if (params[0] != 1 || params[1] != 1 || params[2] != 1)
        return;
    read_size(prog, &reg1, sizeof(char), 0);
    read_size(prog, &reg2, sizeof(char), 0);
    read_size(prog, &reg3, sizeof(char), 0);
    if (reg1 > REG_NUMBER || reg1 < 1 || reg2 > REG_NUMBER ||
    reg2 < 1 || reg3 > REG_NUMBER || reg3 < 1)
        return;
    prog->reg[reg3 - 1] = prog->reg[reg1 - 1] - prog->reg[reg2 - 1];
    prog->carry = 1;
    free(params);
}