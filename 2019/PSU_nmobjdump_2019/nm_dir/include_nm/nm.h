/*
** EPITECH PROJECT, 2020
** nm.h
** File description:
** nm.h
*/

#ifndef NM_H_
#define NM_H_

#include <elf.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct symblist_s {
    unsigned int addr;
    unsigned char type;
    char *name;
    bool isUScore;

    struct symblist_s *prev;
    struct symblist_s *next;
} symblist_t;

typedef struct type_tab_s {
    unsigned char chr;
    unsigned char type;
    unsigned char access;
} type_tab_t;

unsigned char get_sym_type(Elf64_Sym sym, Elf64_Shdr *sHdr);
symblist_t *get_symb(int ac, char *filename);

// -- UTILS-- //
symblist_t *create_new_elem();
symblist_t *push_elem_front(symblist_t *list, symblist_t *newElem);
void print_symb_list(symblist_t *list);
void sort_symb_list(symblist_t *list);
void free_symb_list(symblist_t *list);
char *skip_uscore(symblist_t *elem);

#endif /* !NM_H_ */
