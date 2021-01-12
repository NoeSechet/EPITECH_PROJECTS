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

void analyse_events(sfRenderWindow *window, sfEvent my_event)
{
    while (sfRenderWindow_pollEvent(window, &my_event)) {
        if (my_event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (my_event.type == sfEvtKeyPressed && my_event.key.code ==
            sfKeyEscape)
            sfRenderWindow_close(window);
    }
}

void display(air_list_t **tab_list, tow_list_t *tow_list)
{
    sfRenderWindow *window = window_create(1920, 1080);
    sfClock *my_clock = sfClock_create();
    sfClock *my_clock_launch = sfClock_create();
    sfEvent my_event;
    sfRenderWindow_setFramerateLimit(window, 60);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        analyse_events(window, my_event);
        (tow_list->start != NULL) ? draw_towers(window, tow_list) : 0;
        for (int i = 0; i < 4; i += 1)
            (PARS_TAB_COND) ? update_tab_position(tab_list[i], tab_list, i) : 0;
        for (int i = 0; i < 4; i += 1)
            (PARS_TAB_COND) ? check_collision(tab_list[i]) : 0;
        for (int i = 0; i < 4; i += 1)
            (PARS_TAB_COND) ? draw_planes(window, tab_list[i], my_clock,
            my_clock_launch) : 0;
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}

air_list_t *destroy_tab_list(air_list_t *air_list)
{
    if (air_list == NULL)
        return (NULL);

    if (air_list->start == air_list->end)
    {
        free(air_list);
        air_list = NULL;
        return (NULL);
    }
    aircraft_t *temp = air_list->end;
    air_list->end = air_list->end->previous;
    air_list->end->next = NULL;
    temp->next = NULL;
    temp->previous = NULL;

    free(temp);
    temp = NULL;
    air_list->length -= 1;
    return (air_list);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (my_strncmp(av[1], "-h", 2) == 1) {
        instructions();
        return (0);
    }
    air_list_t *air_list = new_air_list();
    tow_list_t *tow_list = new_tow_list();
    air_list_t **tab_list = NULL;

    void **shapes = (void *[2]){create_rectangle((sfVector2f){0., 50.},
        (sfVector2f){20, 20}), create_circle((sfVector2f){50., 50.}, 10)};
    if ((read_map(av[1], air_list, tow_list, shapes)) == 1)
        return (0);
    tab_list = cut_screen((int[2]){1920, 1080}, 2, 2, air_list);
    display(tab_list, tow_list);
    for (int i = 0; i < 4; i += 1)
            while (tab_list[i] != NULL)
                tab_list[i] = destroy_tab_list(tab_list[i]);
    return (0);
}