/*
** EPITECH PROJECT, 2019
** test_my_strdup
** File description:
** test of my_strdup function
*/

#include "my.h"

Test(my_strdup, display_int)
{
    char dest[6] = {0};

    cr_assert_str_eq(my_strdup("Hello"), "Hello");
}