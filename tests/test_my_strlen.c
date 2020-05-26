/*
** EPITECH PROJECT, 2019
** test_my_strlen
** File description:
** test of my_strlen function
*/

#include "my.h"

Test(my_strlen, display_int)
{
    cr_assert_eq(my_strlen("Hello6"), 6);
    cr_assert_eq(my_strlen_separator("He ;ll o6"), 3);
    cr_assert_eq(my_strlen_separator("He ll o6"), 0);
}