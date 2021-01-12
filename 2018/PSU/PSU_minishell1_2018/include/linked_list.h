/*
** EPITECH PROJECT, 2019
** linked_list.h
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct element_s {
    char *str;
    struct element_s *previous;
    struct element_s *next;
} elem_t;

typedef struct list_s {
    int length;
    elem_t *start;
    elem_t *end;
} list_t;

#endif /* !LINKED_LIST_H_ */