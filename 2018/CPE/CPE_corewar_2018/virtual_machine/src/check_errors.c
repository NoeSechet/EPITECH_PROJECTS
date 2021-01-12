/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** check_open_error.c
*/

#include "lib.h"
#include "program.h"

void check_open_error(char *av, int prog_counter, program_t *prog,
corewar_t *corewar)
{
    if (!av && prog_counter == 0)
        return;
    if (prog_counter >= MAX_ARGS_NUMBER)
        write(2, "The number of champion load is above the limit.\n", 48);
    free(prog);
    free_corewar(corewar);
    exit (84);
}

void check_nbr_champions(corewar_t *corewar)
{
    if (corewar->programs->size == 0) {
        write(2, "No champion specified\n", 22);
        exit(84);
    } else if (corewar->programs->size == 1) {
        write(2, "Usage: ./corewar [-g] ", 22);
        write(2, "[-dump cycle_nb] [[-a load_addr] ", 33);
        write(2, "[-n prog_nb] prog.cor] ...\n", 27);
        exit(84);
    }
}