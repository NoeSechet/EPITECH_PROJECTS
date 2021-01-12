/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** detect_functions.c
*/

#include "lib.h"
#include "utils.h"
#include "program.h"

int detect_dump_cycle(char *flag, char *cycle_to_dump,
corewar_t *corewar)
{
    int res = 0;

    if (!flag || comp_word(flag, "-dump", 5) == -1)
        return (0);
    if (cycle_to_dump == NULL || !is_number(cycle_to_dump)) {
        write(2, "Invalid option\n", 15);
        exit(84);
    }
    res = my_get_nbr(cycle_to_dump);
    if (res < 0) {
        write(2, "-dump argument ", 15);
        my_put_nbr_base(res, "0123456789");
        write(2, " is invalid. Please enter a positive number.\n", 45);
        exit(84);
    }
    corewar->dump_cycle = (unsigned int)res;
    return (1);
}

unsigned int detect_address(char *flag, char *address)
{
    int res = 0;

    if (!flag || comp_word(flag, "-a", 2) == -1)
        return (0);
    if (address == NULL || !is_number(address)) {
        write(2, "Invalid option\n", 15);
        exit(84);
    }
    res = my_get_nbr(address);
    if (res < 0) {
        write(2, "-a argument ", 12);
        my_put_nbr_base(res, "0123456789");
        write(2, " is invalid.\nPlease enter a valid memory offset.\n", 49);
        exit(84);
    }
    return ((unsigned int)res % MEM_SIZE);
}

unsigned int detect_id(char *flag, char *id)
{
    int res = 0;

    if (!flag || comp_word(flag, "-n", 2) == -1)
        return (0);
    if (id == NULL || !is_number(id)) {
        write(2, "Invalid option\n", 15);
        exit(84);
    }
    res = my_get_nbr(id);
    if (res < 0 || res > 4) {
        write(2, "-n argument ", 12);
        my_put_nbr_base(res, "0123456789");
        write(2, " is invalid.\nPlease enter a number between 1 and 4.\n", 53);
        exit(84);
    }
    return ((unsigned int)res);
}