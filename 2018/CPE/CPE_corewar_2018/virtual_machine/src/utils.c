/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** utils.c
*/

#include "program.h"
#include "utils.h"
#include "macros.h"

void read_size(program_t *prog, void *obj, size_t size, int revert)
{
    char *bytes = (char *)obj;

    for (size_t i = 0; i < size; i++)
        bytes[revert ? size - i - 1 : i] = prog->memory[prog->pc + i];
    prog->pc += size;
}

unsigned char *check_coding_byte(program_t *prog)
{
    unsigned char *arg_type = malloc(sizeof(char) * (4 + 1));

    char param = prog->memory[prog->pc++];

    arg_type[0] = param >> 6 & 3;
    arg_type[1] = param >> 4 & 3;
    arg_type[2] = param >> 2 & 3;
    arg_type[3] = param >> 0 & 3;
    arg_type[4] = '\0';

    return (arg_type);
}

int get_params(program_t *prog, int num, int *obj, int address_size)
{
    char codebyte = prog->memory[prog->pc++];
    int value = 0;
    short address = 0;

    switch (codebyte << (num << 1) & 0xFF000000) {
    case 1: value = prog->memory[prog->pc++];
        if (value < 1 || value > REG_NUMBER)
            return (0);
        *obj = prog->reg[value - 1];
        return (1);
    case 2: read_size(prog, &value, sizeof(int), 1);
        *obj = value;
        return (1);
    case 3: read_size(prog, &address, sizeof(short), 1);
        value = address_size == 2 ? *((short *)(prog->memory
        + prog->pc)) : *((int *)(prog->memory + prog->pc));
        *obj = value;
        return (1);
    default: return (0);
    }
}

void write_to_memory(program_t *program, int address[2], void *obj,
    size_t size)
{
    char *value = (char *)obj;

    for (size_t i = 0; i < size; i++) {
        program->memory[address[0] + i] = address[1] ? value[size - i - 1] :
        value[i];
    }
}

int check_end(corewar_t *corewar)
{
    int count = 0;
    program_t *win = 0;

    for (unsigned int i = 0; i < corewar->programs->size; i++) {
        if (((program_t *)corewar->programs->list[i])->is_living) {
            count += 1;
            win = ((program_t *)corewar->programs->list[i]);
        }
    }
    if (count < 2) {
        win = win ? win : corewar->latest;
        write(1, "Le joueur ", 10);
        my_put_nbr_base(win->reg[0], "0123456789");
        write(1, " (", 2);
        write(1, win->header->prog_name, my_strlen(win->header->prog_name));
        write(1, ") a gagné.\n", 11);
    }
    return (count < 2);
}