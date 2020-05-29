/*
** EPITECH PROJECT, 2019
** test_my_strcat
** File description:
** test of my_strcat function
*/

#include "my.h"

Test(my_strcat, display_int)
{
    char astr[] = "Hello ";
    char bstr[] = "World";

    cr_assert_str_eq(my_strcat(astr, bstr), "Hello World");
}