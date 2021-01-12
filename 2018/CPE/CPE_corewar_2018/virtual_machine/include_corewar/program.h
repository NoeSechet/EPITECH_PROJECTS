/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "lib.h"
#include "arraylist.h"

typedef struct program_s {
    unsigned char *memory;
    header_t *header;
    unsigned int pc;
    unsigned int size;
    unsigned int live;
    int carry;
    long cycle;
    char is_living;
    int reg[REG_NUMBER];
    char is_fork;
} program_t;

typedef struct corewar_s {
    unsigned int live;
    unsigned int cycle;
    unsigned int max_cycle;
    unsigned int index;
    unsigned char prog_count;
    unsigned int cycle_to_dump;
    unsigned int dump_cycle;
    program_t *latest;
    arraylist_t *programs;
    unsigned char memory[MEM_SIZE];
} corewar_t;

void live(corewar_t *corewar, program_t *program);
void ld(corewar_t *corewar, program_t *program);
void st(corewar_t *corewar, program_t *prog);
void add(corewar_t *corewar, program_t *prog);
void sub(corewar_t *corewar, program_t *prog);
void and(corewar_t *corewar, program_t *prog);
void or(corewar_t *corewar, program_t *prog);
void xor(corewar_t *corewar, program_t *prog);
void zjmp(corewar_t *corewar, program_t *prog);
void ldi(corewar_t *corewar, program_t *prog);
void sti(corewar_t *corewar, program_t *program);
void fork_core(corewar_t *corewar, program_t *prog);
void lld(corewar_t *corewar, program_t *prog);
void lldi(corewar_t *corewar, program_t *prog);
void lfork_core(corewar_t *corewar, program_t *prog);
void aff(corewar_t *corewar, program_t *prog);

typedef void (* opfunc_t)(corewar_t *, program_t *);

void load_program(int ac, char **av, corewar_t *corewar);
void init_prog_stats(program_t *prog, unsigned int option[3]);
unsigned int available_id(arraylist_t *progs);
void check_open_error(char *av, int prog_counter, program_t *prog,
    corewar_t *corewar);
void check_nbr_champions(corewar_t *corewar);

int detect_dump_cycle(char *flag, char *cycle_to_dump,
corewar_t *corewar);
unsigned int detect_address(char *flag, char *address);
unsigned int detect_id(char *flag, char *id);

void free_corewar(corewar_t *corewar);

#define REGISTRY 1
#define DIRECT 2
#define INDIRECT 3

#endif /* !STRUCT_H_ */