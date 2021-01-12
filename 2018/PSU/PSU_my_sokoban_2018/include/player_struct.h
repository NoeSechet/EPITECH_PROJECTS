/*
** EPITECH PROJECT, 2018
** player_struct.h
** File description:
** player_struct
*/

#ifndef PLAYER_STRUCT_H_
#define PLAYER_STRUCT_H_

typedef struct coord_s {
    int x;
    int y;
} coord_t;

typedef struct player_s {
    coord_t pos;
    int nbr_line;
    int line_max_length;
} player_t;

typedef struct layer_s {
    char **map;
    char **sky;
    char **save;
    int O_count;
    int X_count;
    coord_t **O_tab;
    coord_t **X_tab;
    coord_t O_pos;
    coord_t X_pos;
} layer_t;

typedef struct moves_s {
    int moves;
    int length;
    void(*function_ptr)(layer_t *, player_t *);
} moves_t;

#endif /* !PLAYER_STRUCT_H_ */