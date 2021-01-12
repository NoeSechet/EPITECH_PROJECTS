/*
** EPITECH PROJECT, 2018
** objects
** File description:
** objetcs
*/

#ifndef OBJECT_H_
#define OBJECT_H_

#include <SFML/Graphics.h>
#include "arraylist.h"

typedef struct entity_s {
    unsigned char id;
    float x;
    float y;
    float w;
    float h;
    unsigned char collide;
    void *shape;
    sfColor color;
} entity_t;

typedef struct entitylist_s {
    entity_t **entities;
    int size;
} entitylist_t;

void draw_entity(sfRenderWindow *win, entity_t *ent);
entity_t *new_entity(unsigned char id, float pos[2], float size[2], void *shape);
void circle_rect(entity_t *a, entity_t *b);
void rect_rect(entity_t *a, entity_t *b);
void circle_circle(entity_t *a, entity_t *b);
void entity_collide(entity_t *a, entity_t *b);
void randomize_entitylist(entitylist_t *list, float size[2], void **shapes);
entitylist_t *new_entities(int size);
void check_collision(arraylist_t *entities);
void draw_entities(sfRenderWindow *win, arraylist_t *entities, int reset);
void free_entities(entitylist_t *list);

#endif /* !OBJECT_H_ */