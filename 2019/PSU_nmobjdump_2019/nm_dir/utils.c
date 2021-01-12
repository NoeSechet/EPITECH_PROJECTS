/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** utils.c
*/

#include "nm.h"

symblist_t *create_new_elem(void)
{
    symblist_t *newElem = malloc(sizeof(symblist_t));

    newElem->addr = 0;
    newElem->type = 0;
    newElem->name = NULL;
    newElem->isUScore = false;

    newElem->prev = NULL;
    newElem->next = NULL;

    return newElem;
}

symblist_t *push_elem_front(symblist_t *list, symblist_t *newElem)
{
    symblist_t *temp = NULL;

    if (!newElem)
        return NULL;
    if (list == NULL) {
        list = newElem;
        return list;
    }
    for (temp = list; temp->next != NULL; temp = temp->next);
    temp->next = newElem;
    newElem->prev = temp;

    return list;
}

void print_symb_list(symblist_t *list)
{
    for (symblist_t *temp = list; temp != NULL; temp = temp->next) {
        if (temp->addr == 0 && temp->type != 'T')
            printf("%-17s", "");
        else
            printf("%016x ", (temp->addr));
        printf("%c ", temp->type);
        printf("%s\n", temp->name);
    }
}

void free_symb_list(symblist_t *list)
{
    symblist_t *toDel = NULL;
    for (symblist_t *temp = list; temp != NULL;) {
        toDel = temp;
        temp = temp->next;
        free(toDel);
    }
}

char *skip_uscore(symblist_t *elem)
{
    if (elem == NULL)
        return NULL;

    char *temp = NULL;

    for (temp = elem->name; *temp == '_'; temp += 1) {
        elem->isUScore = true;
    }
    return temp;
}