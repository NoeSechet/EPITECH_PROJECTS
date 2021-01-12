/*
** EPITECH PROJECT, 2018
** arraylist
** File description:
** arraylist
*/

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

typedef struct arraylist_s {
    int size;
    void **list;
} arraylist_t;

arraylist_t *new_arraylist(void);
void arraylist_add(arraylist_t *list, void *obj);
void *arraylist_remove(arraylist_t *list, int index);
void *arraylist_get(arraylist_t *list, int index);

#endif /* !ARRAYLIST_H_ */
