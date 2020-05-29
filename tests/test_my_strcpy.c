/*
** EPITECH PROJECT, 2019
** test_my_strcpy
** File description:
** test of my_strcpy function
*/

#include "my.h"

Test(my_strcpy, display_int)
{
    char dest[6] = {0};

    cr_assert_str_eq(my_strcpy(dest, "Hello"), "Hello");
}