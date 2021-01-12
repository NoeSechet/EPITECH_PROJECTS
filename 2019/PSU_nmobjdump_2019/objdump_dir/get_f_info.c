/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** get_f_info
*/

#include "objd.h"

void print_f_hdr(elf_t *elf)
{
    printf("\n%s     file format %s\n", elf->filename, "elf64-x86-64");
    printf("architecture: %d, flags 0x%08x:\n", elf->ehdr->e_machine,
        elf->ehdr->e_flags);
    
    printf("start address 0x%016lx\n\n", elf->ehdr->e_entry);
}

int get_f_info(char *filename)
{
    elf_t elf;

    if (get_map(&elf, filename) == -1)
        return 1;

    print_f_hdr(&elf);

    return 0;
}