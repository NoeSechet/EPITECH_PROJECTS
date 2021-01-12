/*
** EPITECH PROJECT, 2018
** my_screensaver.c
** File description:
** my_screensaver
*/

#include "utils.h"

anim_t anim_tab[] = {
    {"1", 1, &first_anim},
    {"2", 1, &sec_anim},
    {"3", 1, &third_anim},
    {"4", 1, &fourth_anim},
    {"5", 1, &fifth_anim}
};

void check_anim(char **av, main_t *mains, spritext_t *spritext)
{
    for (int parser = 0; parser < 5; parser += 1) {
        if (my_strncmp(anim_tab[parser].anim, av[1],
                anim_tab[parser].length) == 1) {
            anim_tab[parser].function_ptr(mains, spritext);
        }
    }
}

void open_window(char **av, spritext_t *spritext, main_t *mains)
{
    sfSprite_setTexture(spritext->sprite, spritext->text, sfTrue);
    spritext->clock = sfClock_create();
    while (sfRenderWindow_isOpen(spritext->window)) {
        analyse_events(av, spritext);

        check_anim(av, mains, spritext);

        sfTexture_updateFromPixels(spritext->text, spritext->buf->pixels,
            1800, 1000, 0, 0);
        sfRenderWindow_drawSprite(spritext->window, spritext->sprite, NULL);
        sfRenderWindow_display(spritext->window);
    }
    sfClock_destroy(spritext->clock);
    sfRenderWindow_destroy(spritext->window);
    sfSprite_destroy(spritext->sprite);
    sfTexture_destroy(spritext->text);
}

int instructions(char **av)
{
    if (my_strncmp(av[1], "-h", 2) == 1) {
        h_instructions();
        return (84);
    }
    if (my_strncmp(av[1], "-d", 2) == 1) {
        d_instructions();
        return (84);
    }
    return (0);
}

void display_error_msg(void)
{
    write(2, "./my_screensaver: bad arguments: too many \
(or none) given but 1 is required\nretry with -h\n", 96);
}

int main(int ac, char **av)
{
    spritext_t *spritext = fill_spritext();
    main_t *mains = fill_main_struct();

    if (ac != 2) {
        display_error_msg();
        return (84);
    }
    if (instructions(av) == 84)
        return (84);
    open_window(av, spritext, mains);
    return (0);
}