/*
** EPITECH PROJECT, 2019
** test_my_strcmp
** File description:
** test of my_strcmp function
*/

#include "my.h"

Test(my_strcmp, display_int)
{
    char astr[] = "Hello ";
    char bstr[] = "Hello ";
    char cstr[] = "World";

    cr_assert_eq(my_strcmp(astr, bstr), 0);
    cr_assert_eq(my_strcmp(astr, cstr), -1);
    cr_assert_eq(my_strcmp(cstr, bstr), 1);
}