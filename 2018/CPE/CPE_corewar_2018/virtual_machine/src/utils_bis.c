/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** utils_bis.c
*/

#include "lib.h"
#include "utils.h"

int is_number(char *str)
{
    int i = 0;

    if (!str)
        return (0);

    if (str[0] == '-')
        i += 1;

    for (; str[i] != '\0'; i += 1) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

int comp_word(char const *s1, char const *s2, int length)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (-1);
    for (; (s1[i] != '\0' || s2[i] != '\0') && i < length; i += 1)
        if (s1[i] != s2[i])
            return (-1);
    if (s2[i] != '\0') {
        return (-1);
    }
    return (1);
}

void print_mem(unsigned char *memory, int address)
{
    printf("%x %x %x %x %x %x %x %x\n", memory[address], memory[address + 1], memory[address + 2], memory[address + 3], memory[address + 4], memory[address + 5], memory[address + 6], memory[address + 7]);
}