/*
** EPITECH PROJECT, 2018
** infinadd.c
** File description:
** sum calc
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>

void create_res(char **av, char *str3, char *str4, int a, int b)
{
    int i = 0;
    int j = 0;

    str3[i] = '0';
    i++;
    str4[j] = '0';
    j++;

    for ( ; a > b ; b++, j++)
        str4[j] = '0';
    for ( ; a < b ; a++, i++)
        str3[i] = '0';
    for (int k = 0 ; av[1][k] != '\0' ; k++, i++)
   	    str3[i] = av[1][k];
    for (int y = 0 ; av[2][y] != '\0' ; y++, j++)
	    str4[j] = av[2][y];

    str3[i] = '\0';
    str4[j] = '\0';
}

char *sum(char *str3, char *str4, char *str5, int x)
{
	int nb;
	int i = my_strlen(str3) - 1;
	int j = my_strlen(str4) - 1;
	int s
	x--;
	str5[x] = '\0';
	x--;

	while (str3[i] != '0') { //on additionne 
		nb = ((str3[i] - '0') + (str4[j]) - '0');
		str5[x] = nb % 10 + '0'; //on deplace l'addition sur le res
		x--;
		if (nb / 10 > 0) //on verifie pour la retenue
			str5[x] = str5[x] + 1;
		i--;
		j--;
	}
	return (str5);
}

char *infinadd(char *str3, char *str4, char *str5, int x)
{
	if (str3[0] != '-' && str4[0] != '-')
		sum(str3, str4, str5, x); //when ++
    /*if (str3[0] == '-' && str4[0] == '-')
    	mega_sum(); //when --
    subs; //when +-
    rev - and + subs; //when -+*/
    return (str5);
}

int main(int ac, char **av)
{
	if (ac != 3)
		return (0);

    char *str3;
    char *str4;
    char *str5;
    int a = my_strlen(av[1]);
    int b = my_strlen(av[2]);
    int x = ((a + b) + 1);

    str3 = malloc(sizeof(char) * x);
    str4 = malloc(sizeof(char) * x);

    create_res(av, str3, str4, a, b);

    str5 = malloc(sizeof(char) * x);

    infinadd(str3, str4, str5, x);
    printf("la je crois%s\n", str5);

    return (0);
}

ON DOIT SARRANGER POUR RMEPLIR LA STR5 AVEC DES 'O' !!!!!!!!!!!!