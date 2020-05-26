/*
** EPITECH PROJECT, 2019
** test_my_show_word_array
** File description:
** test of my_show_word_array function
*/

#include "my.h"

Test(my_show_word_array, display_int)
{
    char *str[] = {"Hello", "world", "tank"};

    cr_expect_not(my_show_word_array(str), "Hello\nworld\ntank");
}