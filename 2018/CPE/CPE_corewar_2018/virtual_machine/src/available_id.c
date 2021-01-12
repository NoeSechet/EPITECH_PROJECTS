/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** available_id.c
*/

#include "lib.h"
#include "utils.h"
#include "program.h"

unsigned int available_id(arraylist_t *progs)
{
    int counter = 0;

    for (int i = 1; i < 5; i += 1) {
        counter = 0;
        for (unsigned int j = 0; j < progs->size; j += 1) {
            counter += i == ((program_t *)progs->list[j])->reg[0];
        }
        if (counter == 0)
            return (i);
    }
    exit(84);
}