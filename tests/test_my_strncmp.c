/*
** EPITECH PROJECT, 2019
** test_my_strncmp
** File description:
** test of my_strncmp function
*/

#include "my.h"

Test(my_strncmp, compare_to_string_n_character)
{
    char *s1 = "azdZ";
    char *s2 = "azdA";
    char *s3 = "zebA";

    cr_assert_eq(my_strncmp(s1, s2, 3), 0);
    cr_assert_eq(my_strncmp(s1, s3,1), -1);
    cr_assert_eq(my_strncmp(s3, s1, 2), 1);
}