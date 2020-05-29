/*
** EPITECH PROJECT, 2019
** test_my_strncpy
** File description:
** test of my_strncpy function
*/

#include "my.h"

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    char dest[6] = {0};
    char rest[6] = {0};

    cr_assert_str_eq(my_strncpy(dest, "HelloWorld", 5), "Hello");
}