/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_strlen_separator.c
*/

#include "my.h"

int my_strlen_separator(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ';')
            return (i);
        i++;
    }
    return (0);
}