/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** counts the number of letters in a word (string)
*/

int my_strlen(char const *str)
{
    int a;
    a = 0;
	
    while (str[a] != '\0') {
	a = a + 1;
    }
    return (a);
}
