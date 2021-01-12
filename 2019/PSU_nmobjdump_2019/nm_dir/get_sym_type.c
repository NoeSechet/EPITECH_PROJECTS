/*
** EPITECH PROJECT, 2020
** get_sym_type.c
** File description:
** get_sym_type.c
*/

#include "nm.h"

unsigned char get_simple(Elf64_Sym sym)
{
    unsigned char c = 0;

    if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
        c = 'u';
    else if (ELF64_ST_BIND(sym.st_info) == STB_WEAK) {
        c = 'W';
        if (sym.st_shndx == SHN_UNDEF) {
            c = 'w';
            return c;
        }
    }
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK &&
    ELF64_ST_TYPE(sym.st_info) == STT_OBJECT) {
        c = 'V';
        if (sym.st_shndx == SHN_UNDEF)
            c = 'v';
    }
    return c;
}

unsigned char get_simple2(Elf64_Sym sym)
{
    if (sym.st_shndx == SHN_UNDEF)
        return 'U';
    if (sym.st_shndx == SHN_ABS)
        return 'A';
    if (sym.st_shndx == SHN_COMMON)
        return 'C';

    return 0;
}

unsigned char check_sym_type2(Elf64_Sym sym, Elf64_Shdr *sHdr)
{
    unsigned char c = 0;

    if (sHdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && sHdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        c = 'T';
    else if (sHdr[sym.st_shndx].sh_type == SHT_DYNAMIC)
        c = 'D';
    else
        c = '?';

    return c;
}

unsigned char check_sym_type(Elf64_Sym sym, Elf64_Shdr *sHdr)
{
    unsigned char c = 0;

    if ((c = get_simple(sym)) != 0) {
        return c;
    }
    if ((c = get_simple2(sym)) != 0) {
        return c;
    }
    if (sHdr[sym.st_shndx].sh_type == SHT_NOBITS &&
        sHdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'B';
    if (sHdr[sym.st_shndx].sh_type == SHT_PROGBITS &&
        sHdr[sym.st_shndx].sh_flags == SHF_ALLOC)
        return 'R';
    if (sHdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && sHdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'D';
    c = check_sym_type2(sym, sHdr);
    return c;
}

unsigned char get_sym_type(Elf64_Sym sym, Elf64_Shdr *sHdr)
{
    char c = 0;

    c = check_sym_type(sym, sHdr);

    if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && c != '?')
        c += 32;
    return c;
}