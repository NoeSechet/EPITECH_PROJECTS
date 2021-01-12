/*
** EPITECH PROJECT, 2018
** test_my_pong
** File description:
** test_my_pong
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int pong101(int argc, char **argv);

void redirect_all_std ( void )
{
    cr_redirect_stdout () ;
    cr_redirect_stderr () ;
}

Test (my_printf , test , . init = redirect_all_std )
{
    char *argv[] = {"pong", "1", "2.2", "3", "4", "5", "6.5", "7"};
    pong101(8, argv);
    cr_assert_stdout_eq_str("\nThe velocity vector of the ball is:\n(3.00, 2.80, 3.50)\nAt time t + 7, ball coordinates will be:\n(25.00, 24.60, 31.00)\nThe ball won't reach the bat.");
}