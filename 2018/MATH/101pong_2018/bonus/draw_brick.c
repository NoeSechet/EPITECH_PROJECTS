/*
** EPITECH PROJECT, 2018
** drawbrick
** File description:
** draw brick
*/

#include "bonus.h"

brick_t *fill_brick(int x, int y)
{
    brick_t *new_brick = malloc(sizeof(brick_t));

    new_brick->x = x;
    new_brick->y = y;
    new_brick->hp = 2;
    new_brick->txt = sfTexture_create(950, 850);
    new_brick->spr = sfSprite_create();
    new_brick->update = 1;
    return (new_brick);
}

brick_t **fill_wall(void)
{
    brick_t **brick = malloc(sizeof(brick_t) * (8 * 5));
    int i = 0;
    int y = 0;
    int x;

    while (y < 250)
    {
        x = 0;
        while (x < 950)
        {
            if (x == 448)
                x = x + 56;
            brick[i] = fill_brick(x, y);
            x = x + 112;
            i++;
        }
        y = y + 50;
    }
    return (brick);
}

void brick_colision(sfVector2f *ball, sfVector2f *ball_Velocity,
    brick_t *brick)
{
    if ((ball->y  - 16 >= brick->y && ball->y - 16 <= brick->y + 50) &&
        (ball->x  + 16 >= brick->x && ball->x + 16 <= brick->x + 112)) {
        if (ball->x < brick->x + 50 && ball->x > brick->x)
            ball_Velocity->x = ball_Velocity->x * -1;
        if (ball->y < brick->y + 112 && ball->y > brick->y)
            ball_Velocity->y = ball_Velocity->y * -1;
        brick->hp--;
        brick->update = 1;
    }
}

int draw_brick(sfRenderWindow *window, sfVector2f *ball_coord,
    sfVector2f *ball_Velocity, brick_t *brick)
{
    if (brick->hp <= 0)
        return (0);
    if (brick->hp >= 2 && brick->update == 1) {
        brick->txt = sfTexture_createFromFile("sprite/bbrick.png", NULL);
        brick->update = 0;
    } else if (brick->hp == 1 && brick->update) {
        brick->txt = sfTexture_createFromFile("sprite/bbrickdmg.png", NULL);
        brick->update = 0;
    }
    sfSprite_setTexture(brick->spr, brick->txt, sfTrue);
    sfSprite_setPosition(brick->spr, (sfVector2f){brick->x, brick->y});
    sfRenderWindow_drawSprite(window, brick->spr, NULL);
    brick_colision(ball_coord, ball_Velocity, brick);
    return (1);
}

void draw_wall(sfRenderWindow *window, sfVector2f *ball_coord,
    sfVector2f *ball_Velocity, brick_t **brick)
{
    int i = 0;

    while (brick[i])
    {
        draw_brick(window, ball_coord, ball_Velocity, brick[i]);
        i++;
    }
}