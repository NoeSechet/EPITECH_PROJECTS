/*
** EPITECH PROJECT, 2019
** init_map
** File description:
** init_map
*/

#include "include/utils.h"

int clean_position_order(int *boat_order, int i)
{
    int temp1 = 0;

    if (boat_order[0] > boat_order[2] || boat_order[1] > boat_order[3]) {
        temp1 = boat_order[0];
        boat_order[0] = boat_order[2];
        boat_order[2] = temp1;
        temp1 = boat_order[1];
        boat_order[1] = boat_order[3];
        boat_order[3] = temp1;
    }
    if (boat_order[0] == boat_order[2])
        return ((boat_order[3] - boat_order[1]) + 1 == i ? 1 : 0);
    else
        return ((boat_order[2] - boat_order[0]) + 1 == i ? 1 : 0);

    return (1);
}

int *check_boat_pos(char *line, int i)
{
    int *boat_pos = malloc(sizeof(int) * 4);

    if (check_error(line) == 0 || line[0] != i + 48)
        return (NULL);

    boat_pos[0] = line[2] - 64;
    boat_pos[1] = line[3] - 48;
    boat_pos[2] = line[5] - 64;
    boat_pos[3] = line[6] - 48;

    if (clean_position_order(boat_pos, i) == 0)
        return (NULL);

    return (boat_pos);
}

void fill_map_line(char **map, int boat_length, int *boat_pos)
{
    if (boat_pos[0] == boat_pos[2]) {
        for (int i = 0; i < boat_length; i += 1) {
            map[1 + i + boat_pos[1]][(2 * boat_pos[0] - 1) + 1] =
                boat_length + 48;
        }
    } else {
        for (int i = 0; i < boat_length * 2 - 1; i += 2) {
            map[boat_pos[1] + 1][(2 * boat_pos[0] - 1) + i + 1] =
                boat_length + 48;
        }
    }
}

char **init_map(void)
{
    char **map = malloc(sizeof(char *) * (10 + 1));

    map[0] = strcopy(" |A B C D E F G H");
    map[1] = strcopy("-+---------------");
    map[2] = strcopy("1|. . . . . . . .");
    map[3] = strcopy("2|. . . . . . . .");
    map[4] = strcopy("3|. . . . . . . .");
    map[5] = strcopy("4|. . . . . . . .");
    map[6] = strcopy("5|. . . . . . . .");
    map[7] = strcopy("6|. . . . . . . .");
    map[8] = strcopy("7|. . . . . . . .");
    map[9] = strcopy("8|. . . . . . . .");
    map[10] = NULL;
    return (map);
}

char **create_map(char *script_file)
{
    int fd = 0;
    char *line;
    int *boat_pos = NULL;
    char **map = init_map();

    if ((fd = open(script_file, O_RDONLY)) < 0)
        return (NULL);
    for (int i = 2; (line = get_next_line(fd)) != NULL; i += 1) {
        if ((boat_pos = check_boat_pos(line, i)) == NULL)
            return (NULL);
        fill_map_line(map, line[0] - 48, boat_pos);
    }
    if (check_boat_presence(map) == 0)
        return (NULL);
    return (map);
}