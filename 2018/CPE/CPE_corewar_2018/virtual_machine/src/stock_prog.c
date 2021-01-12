/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** stock_prog.c
*/

#include "program.h"
#include "lib.h"
#include "utils.h"

int check_magic_nbr(header_t *header)
{
    if (header->magic != (int)0xf383ea00) {
        write(2, "Wrong executable magic number.\n", 31);
        return (0);
    }
    return (1);
}

int open_prog_file(char *file_path, program_t *prog, corewar_t *corewar,
unsigned int chosen_address)
{
    int fd = 0;
    off_t size = 0;

    if ((fd = open(file_path, O_RDONLY)) < 0)
        return (0);
    size = lseek(fd, 0, SEEK_END);
    close(fd);
    prog->header = malloc(sizeof(header_t));
    fd = open(file_path, O_RDONLY);
    if (corewar->index + size - sizeof(header_t) > MEM_SIZE)
        exit(84);
    read(fd, prog->header, sizeof(header_t));
    read(fd, corewar->memory + corewar->index, size - sizeof(header_t));
    close(fd);
    prog->memory = corewar->memory;
    prog->pc = chosen_address ? chosen_address : corewar->index;
    prog->size = size - sizeof(header_t);
    corewar->index += MEM_SIZE / corewar->prog_count;
    return (check_magic_nbr(prog->header));
}

void free_corewar(corewar_t *corewar)
{
    program_t *program = 0;

    for (unsigned int i = 0; i < corewar->programs->size; i++) {
        program = corewar->programs->list[i];
        if (!program->is_fork) {
            free(program->header);
        }
        free(corewar->programs->list[i]);
    }
    free(corewar->programs->list);
    free(corewar->programs);
}

void open_program(char *av, unsigned int option[3], corewar_t *corewar)
{
    program_t *prog = malloc(sizeof(program_t));
    static int prog_counter = 0;

    if (!av || open_prog_file(av, prog, corewar, option[0]) == 0 ||
    prog_counter >= MAX_ARGS_NUMBER)
        return (check_open_error(av, prog_counter, prog, corewar));

    init_prog_stats(prog, option);

    arraylist_add(corewar->programs, prog);
    prog_counter += 1;
}

void load_program(int ac, char **av, corewar_t *corewar)
{
    unsigned int chosen_address = 0;
    unsigned int chosen_id = 0;

    for (int i = 1; i < ac; i += 1) {
        detect_dump_cycle(av[i], av[i + 1], corewar) ? i += 2 : 0;
        (chosen_address = detect_address(av[i], av[i + 1])) ? i += 2 : 0;
        (chosen_id = detect_id(av[i], av[i + 1])) ? i += 2 : 0;
        open_program(av[i], (unsigned int[3]){chosen_address, chosen_id,
            available_id(corewar->programs)}, corewar);
    }
    check_nbr_champions(corewar);
}