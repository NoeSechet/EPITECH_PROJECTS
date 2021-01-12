/*
** EPITECH PROJECT, 2018
** ball
** File description:
** ball
*/

#include "bonus.h"

void back_draw(sfRenderWindow *window)
{
    sfTexture *back_txt;
    sfSprite *back_spr;

    back_txt = sfTexture_create(950, 850);
    back_spr = sfSprite_create();
    back_txt = sfTexture_createFromFile("sprite/back.png", NULL);
    sfSprite_setTexture(back_spr, back_txt, sfTrue);
    sfRenderWindow_drawSprite(window, back_spr, NULL);
    if (!(sfRenderWindow_isOpen(window))) {
        sfTexture_destroy(back_txt);
        sfSprite_destroy(back_spr);
    }
}

sfVector2f fill_vector(int x, int y)
{
    sfVector2f coord;

    coord.x = x;
    coord.y = y;
    return (coord);
}

int pong101(sfVector2f *ball_coord, sfVector2f *ball_Velocity,
    sfVector2f bat_coord)
{
    if (ball_coord->x - 15 <= 0 || ball_coord->x - 15 >=  918)
        ball_Velocity->x = ball_Velocity->x * -1;
    if (ball_coord->y - 16 <= 0)
        ball_Velocity->y = ball_Velocity->y * -1;
    if ((ball_coord->y >= bat_coord.y - 15)
        && (ball_coord->x + 15 > bat_coord.x
        && ball_coord->x < bat_coord.x + 138)) {
        ball_Velocity->y = ball_Velocity->y * -1;
        if (ball_coord->x < bat_coord.x + 69)
            ball_Velocity->x = ball_Velocity->x -
                ((ball_coord->x - bat_coord.x) * 0.05);
        if (ball_coord->x > bat_coord.x + 69)
            ball_Velocity->x = ball_Velocity->x +
                ((ball_coord->x - bat_coord.x) * 0.05);
        ball_Velocity->y = ball_Velocity->y * 1.1;
    }
    ball_coord->x = ball_coord->x + ball_Velocity->x;
    ball_coord->y = ball_coord->y + ball_Velocity->y;
    return (0);
}

void draw_ball(sfRenderWindow *window, sfVector2f *ball_coord,
    sfVector2f *ball_Velocity, sfVector2f bat_coord)
{
    sfTexture *ball_txt;
    sfSprite *ball_spr;

    ball_txt = sfTexture_create(950, 850);
    ball_spr = sfSprite_create();
    ball_txt = sfTexture_createFromFile("sprite/ball.png", NULL);
    sfSprite_setOrigin(ball_spr, (sfVector2f){15, 15});
    pong101(ball_coord, ball_Velocity, bat_coord);
    sfSprite_setTexture(ball_spr, ball_txt, sfTrue);
    sfSprite_setPosition(ball_spr, *ball_coord);
    sfSprite_rotate(ball_spr, ball_coord->x * 7);
    sfRenderWindow_drawSprite(window, ball_spr, NULL);
    if (!(sfRenderWindow_isOpen(window))) {
        sfTexture_destroy(ball_txt);
        sfSprite_destroy(ball_spr);
    }
    if (ball_coord->y > 975) {
        *ball_coord = fill_vector(475, 30);
        *ball_Velocity = fill_vector(0, 5);
    }
}