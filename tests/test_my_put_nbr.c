/*
** EPITECH PROJECT, 2019
** test_my_put_nbr
** File description:
** test of my_put_nbr function
*/

#include "my.h"

Test(my_put_nbr, display_int)
{
    int str = 1234;

    cr_expect_not(my_put_nbr(str), "1234");
    cr_expect_not(my_put_nbr(-42), "-42");
}