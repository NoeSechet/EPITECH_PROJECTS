/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** main.c
*/

#include "utils_dante.h"

int finish_sides(maze_t *maze, int x, int y)
{
    int rand_dig = rand() % 2;

    maze->map[strlen(maze->map) - 1] = '*';

    if (x % 2 == 0 && y % 2 == 0) {
        if (rand_dig == 1)
            maze->map[strlen(maze->map) - (x + 2)] = '*';
        else
            maze->map[strlen(maze->map) - 2] = '*';
    }
    return (1);
}

void destroy_maze(maze_t *maze)
{
    free(maze->map);
    maze->map = NULL;
    free(maze);
}

int create_perfect_maze(int x, int y)
{
    maze_t *maze = NULL;

    if (x == 0 || y == 0)
        return (-1);
    maze = init_maze_struct(x, y, 1);
    dig_maze(maze);
    if (x % 2 == 0 || y % 2 == 0)
        finish_sides(maze, x, y);
    printf("%s", maze->map);
    destroy_maze(maze);
    return (1);
}

int create_imperfect_maze(int x, int y)
{
    maze_t *maze = NULL;

    if (x == 0 || y == 0)
        return (-1);
    maze = init_maze_struct(x, y, -1);
    dig_maze(maze);
    if (x % 2 == 0 || y % 2 == 0)
        finish_sides(maze, x, y);
    printf("%s", maze->map);
    destroy_maze(maze);
    return (1);
}

int main(int ac, char **av)
{
    int error_handling = 0;
    int index_comp = 0;

    srand(time(NULL));

    if (ac != 3 && ac != 4)
        exit(84);
    if (ac == 3)
        error_handling = create_imperfect_maze(atoi(av[1]), atoi(av[2]));
    else if (ac == 4 && (index_comp = strcmp(av[3], "perfect")) == 0)
        error_handling = create_perfect_maze(atoi(av[1]), atoi(av[2]));

    if (error_handling == -1 || index_comp < 0) {
        return (84);
    }
    return (0);
}