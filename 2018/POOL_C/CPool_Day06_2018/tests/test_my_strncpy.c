/*
** EPITECH PROJECT, 2018
** test_my_strncpy.c
** File description:
** test choose the number of letters you wanna display in the dest.
*/

#include <criterion/criterion.h>

char *my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, copy_string_in_empty_array)
{
    char dest[6] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strncpy, if_n_is_bigger_than_s)
{
	char dest[12] = {0};

    my_strncpy(dest, "HelloWorld", 130);
    cr_assert_str_eq(dest, "HelloWorld");
}
