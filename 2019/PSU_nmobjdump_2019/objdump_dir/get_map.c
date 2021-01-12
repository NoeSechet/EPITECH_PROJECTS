/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** get_map
*/

#include "objd.h"

int check_elf_format(elf_t *elf)
{
    if (elf->len < sizeof(Elf64_Ehdr) || memcmp(elf->ehdr, "\177ELF", 4)) {
        fprintf(stderr, "objdump: %s: file format not recognized\n",
        elf->filename);
        return -1;
    }
    if ((void *)(elf->shdr = ((void *)elf->ehdr + elf->ehdr->e_shoff)) >
    elf->end_file ||
    (void *)&elf->shdr[elf->ehdr->e_shstrndx] > elf->end_file ||
    (void *)(void *)elf->ehdr + elf->shdr[elf->ehdr->e_shstrndx].sh_offset >
    elf->end_file) {
        fprintf(stderr, "Error : invalid file\n");
        return -1;
    }
    elf->strtab = (char *)(void *)elf->ehdr + elf->shdr[
        elf->ehdr->e_shstrndx
    ].sh_offset;
    return 0;
}

int get_map(elf_t *elf, char *filename)
{
    int fd = 0;
    struct stat s;

    elf->filename = filename;
    if ((fd = open(filename, O_RDONLY)) == -1) {
        fprintf(stderr, "nm: '%s': No such file\n", filename);
        return -1;
    }
    if ((elf->len = lseek(fd, 0, SEEK_END)) == (unsigned)-1)
        return -1;
    fstat(fd, &s);
    if (S_ISDIR(s.st_mode)) {
        fprintf(stderr, "nm: Warning: '%s' is a directory\n", filename);
        return -1;
    }
    if ((elf->ehdr = mmap(NULL , elf->len, PROT_READ, MAP_SHARED, fd, 0))
        == NULL) return -1;
    close(fd);
    elf->end_file = (void *)elf->ehdr + elf->len;
    return check_elf_format(elf);
}