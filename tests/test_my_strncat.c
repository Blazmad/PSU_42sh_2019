/*
** EPITECH PROJECT, 2019
** test_my_strncat
** File description:
** test of my_strncat function
*/

#include "my.h"

Test(my_strncat, display_int)
{
    char astr[] = "Hello toi";
    char bstr[] = "World ";

    cr_assert_str_eq(my_strncat(bstr, astr, 4), "World Hell");
}