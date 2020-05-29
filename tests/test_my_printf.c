/*
** EPITECH PROJECT, 2019
** testrintf
** File description:
** test of my_printf function
*/

#include "my.h"

Test(my_printf, display_int)
{
    int i = 1234;
    unsigned int un_i = 99;
    char t = 't';
    char str[] = "Hello";
    char str_b[] = "Ha";

    cr_expect_not(my_printf("j'ai %d e%c ans", i, t), "j'ai 1234 et ans");
    cr_expect_not(my_printf("%s toi !"), "Hello toi !");
    cr_expect_not(my_printf("%u / %S / %b / %o", un_i, str, str_b, un_i),
        "99 / HELLO / 01001000 01100001 / 143");
    cr_expect_not(my_printf("%x / %X / %p %%", i, i),
        "4d2 / 4D2 / 0x4df6bb2a %");
    cr_expect_not(my_printf("A+% C % B0%+ G#%-%0"), "A+C B 0G#0x");
}