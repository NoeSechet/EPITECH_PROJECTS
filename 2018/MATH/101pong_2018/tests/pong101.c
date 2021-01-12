/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "pong.h"

ball_t *fill_struct(char **argv)
{
    ball_t *ball = malloc(sizeof(ball_t));

    if (ball == NULL)
        exit (84);

    ball->x = atof(argv[4]);
    ball->y = atof(argv[5]);
    ball->z = atof(argv[6]);
    ball->vx = ball->x - atof(argv[1]);
    ball->vy = ball->y - atof(argv[2]);
    ball->vz = ball->z - atof(argv[3]);
    ball->t = atoi(argv[7]);
    if (ball->t < 0) {
        free(ball);
        exit (84);
    }
    return (ball);
}

int find_angle(ball_t *ball)
{
    float result = 0;
    float pi = 3.141592653589793;

    if ((ball->z > 0 && ball->vz >= 0) || (ball->z < 0 && ball->vz <= 0)) {
        printf("The ball won't reach the bat.\n");
        return (-1);
    }
    printf("The incidence angle is:\n");
    result = pow(ball->vx, 2) + pow(ball->vy, 2);
    if (result == 0) {
        printf("90.00 degrees\n");
        return (0);
    }
    result = result / (sqrt(pow(ball->vx, 2) + pow(ball->vy, 2) +
        pow(ball->vz, 2)) * (sqrt(pow(ball->vx, 2) + pow(ball->vy, 2))));
    result = acos(result) / pi * 180;
    printf("%.2f degrees\n", result);
    return (0);
}

void instructions(void)
{
    write(1, "USAGE\n", 6);
    write(1, "        ./101pong xO yO zO x1 y1 z1 t\n\n", 39);
    write(1, "DESCRIPTION\n", 12);
    write(1, "        xO    ball abscissa at time t - 1\n", 43);
    write(1, "        yO    ball ordinate at time t - 1\n", 42);
    write(1, "        zO    ball altitude at time t - 1\n", 42);
    write(1, "        x1    ball abscissa at time t\n", 38);
    write(1, "        y2    ball ordinate at time t\n", 38);
    write(1, "        z3    ball altitude at time t\n", 38);
    write(1, "        n     time shift (greater than or equal ", 48);
    write(1, "to zero, integer)\n", 18);
}

int pong101(int argc, char **argv)
{
    ball_t *ball;

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h'
        && argv[1][2] == '\0')
        instructions();
    if (argc != 8)
        return (84);
    ball = fill_struct(argv);
    if (ball->vx == 0 && ball->vy == 0 && ball->vz == 0) {
        free (ball);
        return (84);
    }
    printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\n",
        ball->vx, ball->vy, ball->vz);
    printf("At time t + %d, ball coordinates will be:\n(%.2f, %.2f, %.2f)\n",
        ball->t, ball->x + ball->vx * ball->t, ball->y + ball->vy * ball->t,
        ball->z + ball->vz * ball->t);
    find_angle(ball);
    free(ball);
    return (0);
}