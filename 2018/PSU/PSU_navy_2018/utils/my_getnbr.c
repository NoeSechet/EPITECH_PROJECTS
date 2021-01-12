/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/

int show_num(char const *str, int nb, int i)
{
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return (nb);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int n = 0;

    if (str[i] == '\0')
        return (0);
    if (!(str[i] >= '0' && str[i] <= '9') && (str[i] != '-' && str[i] != '+' ))
            return (-2);
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
                n++;
        i++;
    }
    nb = show_num(str, nb, i);
    if (n % 2 == 1) {
        nb = -nb;
        return (-1);
    }
    return (nb);
}