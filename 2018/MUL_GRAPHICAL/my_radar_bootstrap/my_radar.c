/*
** EPITECH PROJECT, 2018
** my_radar.c
** File description:
** my_radar
*/

#include "utils.h"

sfRenderWindow *window_create(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode window_mode;

    window_mode.width = width;
    window_mode.height = height;
    window_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(window_mode,
        "window", sfDefaultStyle, NULL);
    return (window);
}

void analyse_events(sfRenderWindow *window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
    }
}

arraylist_t **cut_screen(int size[2], int w, int h, entitylist_t *list)
{
    arraylist_t **newlist = malloc(sizeof(arraylist_t *) * (w * h + 1));
    int x = 0;
    int y = 0;
    int width = size[0] / w;
    int height = size[1] / h;
    int colors[w * h];

    for (int i = 0; i < w * h; i++) {
        newlist[i] = new_arraylist();
        colors[i] = rand() % 0xFFFFFF;
    }
    for (int i = 0; i < list->size; i++) {
        x = list->entities[i]->x / width;
        y = list->entities[i]->y / height;
        if (x < w && y < h) {
            list->entities[i]->color = sfColor_fromInteger(colors[x + y * w] << 8 | 0xFF);
            arraylist_add(newlist[x + y * w], list->entities[i]);
        }
    }
    newlist[w * h] = 0;
    return (newlist);
}

int main(void)
{
    sfRenderWindow *window = window_create(1000, 800);
    void **shapes = (void *[2]){create_rectangle((sfVector2f){0., 0.},
    (sfVector2f){10, 10}), create_circle((sfVector2f){0., 0.}, 10)};
    entitylist_t *list = new_entities(1000);
    arraylist_t **entities = 0;
    sfVector2i pos;

    randomize_entitylist(list, (float[2]){1000, 800}, shapes);
    entities = cut_screen((int[2]){1000, 800}, 8, 4, list);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        analyse_events(window);
        pos = sfMouse_getPositionRenderWindow(window);
        list->entities[0]->x = pos.x;
        list->entities[0]->y = pos.y;
        for (int i = 0; entities[i]; i++)
            check_collision(entities[i]);
        for (int i = 0; entities[i]; i++)
            draw_entities(window, entities[i], 1);
        sfRenderWindow_display(window);
    }
    free_entities(list);
    destroy_shapes(shapes);
    sfRenderWindow_destroy(window);
    return (0);
}