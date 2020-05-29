/*
** EPITECH PROJECT, 2019
** test_my_putstr
** File description:
** test of my_putstr function
*/

#include "my.h"

Test(my_putstr, display_int)
{
    char str[] = "HelloWorld";

    cr_expect_not(my_putstr(str), "HelloWorld");
}