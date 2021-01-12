/*
** EPITECH PROJECT, 2018
** my_sokoban.c
** File description:
** my_sokoban
*/

#include "utils.h"

const moves_t moves_tab[] = {
    {KEY_UP, 1, &moves_up},
    {KEY_DOWN, 1, &moves_down},
    {KEY_RIGHT, 1, &moves_right},
    {KEY_LEFT, 1, &moves_left},
    {' ', 1, &reset_map},
    {0, 0, NULL}
};

void memalloc_layer(layer_t *layer, ssize_t len_read, int s)
{
    layer->map[s] = malloc(sizeof(char) * (len_read + 1));
    layer->sky[s] = malloc(sizeof(char) * (len_read + 1));
    layer->save[s] = malloc(sizeof(char) * (len_read + 1));
    layer->map[s][len_read] = '\0';
    layer->sky[s][len_read] = '\0';
    layer->save[s][len_read] = '\0';
}

void read_file(char *file, player_t *player, layer_t *layer)
{
    char *line = NULL;
    size_t size = 0;
    int s = 0;
    ssize_t len_read = 0;

    layer->map = malloc(sizeof(char *) * player->nbr_line);
    layer->sky = malloc(sizeof(char *) * player->nbr_line);
    layer->save = malloc(sizeof(char *) * player->nbr_line);
    FILE *str = fopen(file, "r");
    (str == NULL ? exit (84) :0);
    while ((len_read = getline(&line, &size, str)) > 0) {
        line[len_read] = '\0';
        if (len_read > player->line_max_length)
            player->line_max_length = len_read;
        memalloc_layer(layer, len_read, s);
        fill_layer(line, layer, s);
        s += 1;
    }
    layer->map[s] = NULL;
    layer->sky[s] = NULL;
    layer->save[s] = NULL;
}

void check_getch_value(layer_t *layer, int input, player_t *player)
{
    for (int parser = 0; moves_tab[parser].moves != 0; parser += 1) {
        if (moves_tab[parser].moves == input)
            moves_tab[parser].function_ptr(layer, player);
    }
}

void display_map(layer_t *layer, player_t *player)
{
    int input;
    initscr();
    keypad(stdscr, TRUE);
    while (1) {
        if (getmaxx(stdscr) < player->line_max_length ||
                getmaxy(stdscr) < player->nbr_line + 1)
            display_message();
        else {
            clear();
            print_map(layer->map);
            move (0, 0);
            print_sky(layer->sky);
            move (0, 0);
            refresh();
            win_lose_cond(layer);
            input = getch();
            check_getch_value(layer, input, player);
        }
    }
    endwin();
}

int main(int ac, char **av)
{
    if (ac != 2)
        exit (84);
    instructions(av);
    player_t *player = fill_player_struct();
    layer_t *layer = malloc(sizeof(layer_t));
    nbr_length_line(av[1], player, layer);
    read_file(av[1], player, layer);
    fill_player_pos(layer, player);
    display_map(layer, player);
    free(player);
    free(layer);
    return (0);
}