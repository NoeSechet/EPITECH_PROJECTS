/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** live.c
*/

#include "program.h"
#include "utils.h"
#include "macros.h"

void check_living(corewar_t *corewar)
{
    for (unsigned int i = 0; i < corewar->programs->size; i++) {
        if (((program_t *)corewar->programs->list[i])->is_living) {
            ((program_t *)corewar->programs->list[i])->is_living =
                ((program_t *)corewar->programs->list[i])->live > 0;
            ((program_t *)corewar->programs->list[i])->live = 0;
        }
    }
}

void write_live_sig(program_t *prog, int value)
{
    write(1, "Le joueur ", 10);
    my_put_nbr_base(value, "0123456789");
    write(1, " (", 2);
    write(1, prog->header->prog_name, my_strlen(prog->header->prog_name));
    write(1, ") est en vie.\n", 14);
}

void live(corewar_t *corewar, program_t *program)
{
    int value = 0;
    program_t *prog = NULL;

    read_size(program, &value, sizeof(int), 1);
    // printf("%s: %d -> %d\n", program->header->prog_name, program->reg[0], value);
    for (unsigned int i = 0; i < corewar->programs->size; i++) {
        prog = (program_t *)corewar->programs->list[i];
        if (prog->reg[0] == value) {
            prog->live += 1;
            break;
        }
    }
    if (prog) {
        corewar->latest = prog;
        write_live_sig(prog, prog->reg[0]);
    }
    corewar->live += 1;
    if (corewar->live >= NBR_LIVE) {
        corewar->live = 0;
        corewar->max_cycle -= CYCLE_DELTA;
    }
}