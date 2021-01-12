/*
** EPITECH PROJECT, 2019
** str
** File description:
** str
*/

#include "utils.h"

int count_nb_of_word(char *str, char c)
{
    int nb_word = 1;

    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i + 1] != '\0' && str[i + 1] != '\n' && str[i + 1] != c &&
        str[i + 1] != '\t') && (str[i] == c || str[i] == '\t'))
            nb_word++;
    }
    return (nb_word);
}

int length_word(char *str, int pos)
{
    for (; str[pos] != '\0' && str[pos] != '\t' && str[pos] != '\n'; pos += 1);
    return (pos);
}

char *str_to_board(char *str, int *pos, char c)
{
    int end = length_word(str, *pos);
    char *result = malloc (sizeof(char) * (end + 1));
    int i = 0;

    for (; str[*pos] != '\0' && str[*pos] != '\n' && str[*pos] != '\t'
    && str[*pos] != c; i++, *pos += 1)
        result[i] = str[*pos];
    result[i] = '\0';
    return (result);
}

char **str_to_word_array(char *str, char c)
{
    int pos = 0;
    char **board = malloc(sizeof(char *) * (count_nb_of_word(str, c) + 1));

    for (int i = 0; i < count_nb_of_word(str, c); i++) {
        for (; str[pos] != '\0' && (str[pos] == c || str[pos] == '\t'); pos++);
        board[i] = str_to_board(str, &pos, c);
    }
    board[count_nb_of_word(str, c)] = NULL;
    return (board);
}