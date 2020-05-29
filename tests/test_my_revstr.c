/*
** EPITECH PROJECT, 2019
** test_my_revstr
** File description:
** test of my_revstr function
*/

#include "my.h"

Test(my_revstr, copy_five_characters_in_empty_array)
{
    char dest[] = "hello";

    my_revstr(dest);
    cr_assert_str_eq(dest, "olleh");
}