/*
** EPITECH PROJECT, 2019
** test_my_strstr
** File description:
** test of my_strstr function
*/

#include "my.h"

Test(my_strstr, copy_characters_in_empty_array)
{
    char *res0 = my_strstr("hello", "lo");
    cr_assert_str_eq(res0, "lo");
}