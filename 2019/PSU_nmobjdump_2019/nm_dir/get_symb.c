/*
** EPITECH PROJECT, 2020
** get_symb.c
** File description:
** get_symb.c
*/

#include "nm.h"

bool check_elf_format(char *buf, char *filename)
{
    char *elf_ID = NULL;

    if (buf == NULL)
        return false;
    elf_ID = buf;
    if (*elf_ID == 0x7f && buf[1] == 'E' && buf[2] == 'L' && buf[3] == 'F')
        return true;
    fprintf(stderr, "nm: %s: file format not recognized\n", filename);

    return false;
}

void *get_map(char *filename)
{
    int fd = 0;
    void *buf = NULL;
    struct stat s;

    if ((fd = open(filename, O_RDONLY)) == -1) {
        fprintf(stderr, "nm: '%s': No such file\n", filename);
        return NULL;
    }
    stat(filename, &s);
    if (S_ISDIR(s.st_mode)) {
        fprintf(stderr, "nm: Warning: '%s' is a directory\n", filename);
        return NULL;
    }
    fstat(fd, &s);
    buf = mmap(NULL , s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == NULL)
        perror("mmap");
    close(fd);
    return buf;
}

symblist_t *parse_symb_tab(Elf64_Shdr *sHdr, Elf64_Shdr *symtabHdr,
Elf64_Sym *symtab, char *add_str)
{
    symblist_t *list = NULL;
    symblist_t *newElem = NULL;
    unsigned char symType = 0;

    for (size_t i = 0; i < symtabHdr->sh_size / symtabHdr->sh_entsize; i++) {
        symType = get_sym_type(symtab[i], sHdr);
        if ((strcmp(add_str + symtab[i].st_name, "") != 0) && symType != 'a') {
            newElem = create_new_elem();
            if (symtab[i].st_value != 0 || symType == 'T')
                newElem->addr = symtab[i].st_value;
            newElem->type = symType;
            newElem->name = add_str + symtab[i].st_name;
            list = push_elem_front(list, newElem);
        }
    }
    return list;
}

symblist_t *get_symb_tab_hdrs(void *buf, Elf64_Ehdr *elf)
{
    Elf64_Shdr *sHdr = NULL;
    char *add_str = NULL;
    Elf64_Shdr *symtabHdr = NULL;
    Elf64_Shdr *strtabHdr = NULL;
    Elf64_Sym *symtab = NULL;

    sHdr = (Elf64_Shdr *)((char *)buf + elf->e_shoff);
    add_str = ((char *)buf + sHdr[elf->e_shstrndx].sh_offset);

    for (size_t i = 0; i < elf->e_shnum; i += 1) {
        if (!sHdr[i].sh_size)
            continue;
        if (sHdr[i].sh_type == SHT_SYMTAB)
            symtabHdr = (Elf64_Shdr *)(&sHdr[i]);
        else if (strcmp(&add_str[sHdr[i].sh_name], ".strtab") == 0)
            strtabHdr = (Elf64_Shdr *)(&sHdr[i]);
    }
    symtab = (Elf64_Sym *)(buf + symtabHdr->sh_offset);
    add_str = (char *)(buf + strtabHdr->sh_offset);
    return parse_symb_tab(sHdr, symtabHdr, symtab, add_str);
}

symblist_t *get_symb(int ac, char *filename)
{
    void *buf = NULL;
    Elf64_Ehdr *elf = NULL;

    if ((buf = get_map(filename)) == NULL ||
    check_elf_format((char *)buf, filename) == false)
        return NULL;
    elf = (Elf64_Ehdr *)buf;

    if (ac > 2)
        printf("\n%s:\n", filename);

    return get_symb_tab_hdrs(buf, elf);
}