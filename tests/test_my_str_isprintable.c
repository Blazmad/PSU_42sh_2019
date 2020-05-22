/*
** EPITECH PROJECT, 2019
** test_my_str_isprintable
** File description:
** test of my_str_isprintable function
*/

#include "my.h"

Test(my_str_isprintable, return_1_is_printable)
{
    int res = my_str_isprintable("HelloWorld\n");
    cr_assert_eq(res, 0);
}