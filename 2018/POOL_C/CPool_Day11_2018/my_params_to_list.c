/*
** EPITECH PROJECT, 2018
** my_params_to_list.c
** File description:
** creates a new list from the command line argument, the adress of the first node is returned
*/

#include "mylist.h"
#include <stdlib.h>
#include "my.h"

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *res = NULL;
    linked_list_t *element;

    for (int i = 0 ; i < ac ; i++) {
    	element = malloc(sizeof(*element));
    	element->data = av[i];
    	element->next = res;
    	res = element;
    }
    return (res);
}
