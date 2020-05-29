/*
** EPITECH PROJECT, 2019
** test_my_getnbr
** File description:
** test of my_getnbr function
*/

#include "my.h"

Test(my_getnbr, convert_str_into_int)
{
    char str[] = "hello42sh";

    cr_assert_eq(my_getnbr(str), 42);
}

Test(my_getnbr, convert_char_into_int)
{
    char str[] = "1";

    cr_assert_eq(my_getnbr(str), 1);
}