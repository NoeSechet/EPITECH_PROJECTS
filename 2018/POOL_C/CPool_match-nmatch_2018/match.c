/*
** EPITECH PROJECT, 2018
** match.c
** File description:
** checking if 1 string matches another
*/

#include <stdio.h>

int match(char const *s1, char const *s2)
{
    if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
        return (1);

    if (*s1 != 0 && *s2 == '*')
	return (1);
    
    if (*s1 == '\0' || *s2 == '\0')//cas d'erreursi un des deux estegal a 0//
	return (0);
    
    if (s1[0] == s2[0] || s2[0] == '*')
	    return(match(s1 + 1, s2));
 
    if (s1[0] != s2[0])
	    return(match(s1 -1, s2 + 1));

    if (*s2 == '*' && *s1 == '\0')
	    return (1);

    return (0);
}
