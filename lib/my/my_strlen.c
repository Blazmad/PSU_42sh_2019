/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** counts and returns the number of characters found in the string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

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