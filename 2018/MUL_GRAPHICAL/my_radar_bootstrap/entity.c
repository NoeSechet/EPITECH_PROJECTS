/*
** EPITECH PROJECT, 2018
** entity
** File description:
** entity
*/

#include "utils.h"
#include <stdlib.h>

entity_t *new_entity(unsigned char id, float pos[2], float size[2], void *shape)
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->id = id;
    entity->x = pos[0];
    entity->y = pos[1];
    entity->w = size[0];
    entity->h = size[1];
    entity->shape = shape;
    entity->collide = 0;
    return (entity);
}

entitylist_t *new_entities(int size)
{
    entitylist_t *list = malloc(sizeof(entitylist_t));

    list->entities = malloc(sizeof(entity_t *) * size);
    list->size = size;
    for (int i = 0; i < size; i++)
        list->entities[i] = new_entity(0, (float[2]){0, 0},
        (float[2]){2, 2}, 0);
    return (list);
}

void randomize_entitylist(entitylist_t *list, float size[2], void **shapes)
{
    srand(time(NULL));

    for (int i = 0; i < list->size; i++) {
        list->entities[i]->x = (rand() % 255 / 255.) * size[0];
        list->entities[i]->y = (rand() % 255 / 255.) * size[1];
        list->entities[i]->w = (rand() % 255 / 255.) * 10 + 1;
        list->entities[i]->h = (rand() % 255 / 255.) * 10 + 1;
        list->entities[i]->id = rand() % 2;
        list->entities[i]->shape = shapes[list->entities[i]->id];
    }
}

void free_entities(entitylist_t *list)
{
    for (int i = 0; i < list->size; i++)
            free(list->entities[i]);
        free(list->entities);
        free(list);
}