/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** to_array_command.c
*/

#include "my.h"

void clean_to_array(stru_t *stru)
{
    for (int i = 0; stru->tmp[i]; i++) {
        stru->tmp[i] = move_spaces(stru->tmp[i]);
        if (stru->tmp[i][0] == '\0')
            stru->tmp[i] = NULL;
    }
}

int count_charact(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i]) {
        if (str[i] == ';')
            return (count);
        count++;
        i++;
    }
    return (count);
}

int count_line(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i]) {
        if (str[i] == ';')
            count++;
        i++;
    }
    return (count + 1);
}

char **make_double_array_tmp(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **array = malloc(sizeof(char *) * (count_line(str) + 1));

    for (; i < count_line(str); i++, k++) {
        array[i] = malloc(sizeof(char) * count_charact(str) + 1);
        for (j = 0; str[k] != ';' && str[k] != '\0'; j++, k++) {
            array[i][j] = str[k];
        }
        array[i][j] = '\0';
    }
    array[i] = NULL;
    return (array);
}