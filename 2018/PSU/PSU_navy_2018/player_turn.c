/*
** EPITECH PROJECT, 2019
** player_turn
** File description:
** player_turn
*/

#include "utils.h"

int check_arg(char *input)
{
    if (my_strlen(input) != 2)
        return (0);
    if (is_right_letter(input[0]) == 0)
        return (0);
    if (is_right_nbr(input[1]) == 0)
        return (0);
    return (1);
}

char *get_arg(void)
{
    char *input = NULL;

    my_printf("\nattack: \e[3m");
    if ((input = get_next_line(0)) == NULL)
        return (NULL);
    if (check_arg(input) == 0) {
        my_printf("\e[0mwrong position");
        return (get_arg());
    }
    my_printf("\e[0m");
    return (input);
}

int convert_arg_to_int(char *str)
{
    int bomb_pos = 0;
    int y = str[1] - 48;
    int x = (str[0] - 65) + 1;

    bomb_pos = ((y - 1) * 8) + x;
    free(str);
    return (bomb_pos);
}

int player_turn(char **map_player_2, int pid_player_2)
{
    (void)map_player_2;
    char *input = NULL;
    int bomb_pos = 0;

    if ((input = get_arg()) == NULL)
        return (0);
    my_printf("%s: ", input);
    bomb_pos = convert_arg_to_int(input);;
    send_signal(bomb_pos, pid_player_2);

    hit_or_missed(bomb_pos, map_player_2);
    return (1);
}