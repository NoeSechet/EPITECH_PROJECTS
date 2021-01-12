/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** main.c
*/

#include "program.h"
#include "lib.h"
#include "macros.h"
#include "utils.h"

#define OP_MAX 16

static const opfunc_t opcodes[] = {
    live,
    ld,
    st,
    add,
    sub,
    and,
    or,
    xor,
    zjmp,
    ldi,
    sti,
    fork_core,
    lld,
    lldi,
    lfork_core,
    aff
};

void dump_memory(corewar_t *corewar)
{
    static const char *hex = "0123456789ABCDEF";
    unsigned char byte = 0;
    int count = 0;

    for (int i = 0; i < MEM_SIZE; i++) {
        byte = corewar->memory[i];
        write(1, &hex[(byte >> 4) & 0xF], 1);
        write(1, &hex[byte & 0xF], 1);
        count += 1;
        if (count >= 32) {
            count = 0;
            write(1, "\n", 1);
        } else {
            write(1, " ", 1);
        }
    }
}

void execute_programs(corewar_t *corewar, program_t **progs)
{
    char op = 0;

    for (unsigned char i = 0; i < corewar->programs->size; i++) {
        if (!progs[i]->is_living)
            continue;
        op = progs[i]->memory[progs[i]->pc];
        if (progs[i]->cycle < 0 && op - 1 < OP_MAX) {
            progs[i]->cycle = op_tab[op - 1].nbr_cycles;
        } else if (progs[i]->cycle == 0 && op - 1 < OP_MAX && opcodes[op - 1]) {
            // printf("[%d] Name: %s OP: %d\n", progs[i]->reg[0], progs[i]->header->prog_name, op);
            progs[i]->pc += 1;
            opcodes[op - 1](corewar, progs[i]);
            op = progs[i]->memory[progs[i]->pc];
            progs[i]->cycle = op_tab[op - 1].nbr_cycles;
        } else if (op - 1 >= OP_MAX || !opcodes[op - 1]) {
            progs[i]->pc += 1;
        }
        progs[i]->cycle -= 1;
    }
}

void run_loop(corewar_t *corewar)
{
    while (check_end(corewar) == 0) {
        execute_programs(corewar, (program_t **)corewar->programs->list);
        corewar->cycle += 1;
        corewar->cycle_to_dump += 1;
        if (corewar->cycle > corewar->max_cycle) {
            check_living(corewar);
            corewar->cycle = 0;
        }
        if (corewar->dump_cycle > 0 && corewar->cycle_to_dump >
            corewar->dump_cycle) {
            dump_memory(corewar);
            corewar->cycle_to_dump = 0;
        }
    }
}

int init(int ac, char **av)
{
    corewar_t corewar;

    corewar.programs = new_arraylist(0);
    corewar.live = 0;
    corewar.latest = 0;
    corewar.cycle = 0;
    corewar.max_cycle = CYCLE_TO_DIE;
    corewar.index = 0;
    corewar.dump_cycle = 0;
    corewar.cycle_to_dump = 0;
    for (int i = 1; i < MEM_SIZE; i++)
        corewar.memory[i] = 0;
    corewar.prog_count = ac - 1;
    load_program(ac, av, &corewar);
    run_loop(&corewar);
    free_corewar(&corewar);
    return (0);
}

int main(int ac, char **av)
{
    return (init(ac, av));
}