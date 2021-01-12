/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** aff.c
*/

#include "lib.h"
#include "program.h"
#include "utils.h"
#include "macros.h"

void aff(corewar_t *corewar UNUSED, program_t *prog)
{
    unsigned char *params = check_coding_byte(prog);
    char reg_index = 0;
    char val_ascii UNUSED = 0;

    if (params[0] != 1)
        return;
    read_size(prog, &reg_index, sizeof(char), 1);
    if (reg_index > REG_NUMBER || reg_index < 1)
        return;
    val_ascii = prog->reg[reg_index -1] % 256;
}