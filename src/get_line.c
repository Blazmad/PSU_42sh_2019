/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** get_line.c
*/

#include "my.h"

int count_line_lines(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i]) {
        if (str[i] == ' ')
            count++;
        i++;
    }
    return (count + 1);
}

int count_line_char(char *str, int i)
{
    int count = 0;

    while (str[i]) {
        if (str[i] == ' ' || str[i] == '\0')
            return (count);
        count++;
        i++;
    }
    return (count);
}

char **make_double_array_line(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **array = malloc(sizeof(char *) * (count_line_lines(str) + 1));

    for (; i < count_line_lines(str); i++, k++) {
        array[i] = malloc(sizeof(char) * count_line_char(str, k) + 1);
        for (j = 0; str[k] != ' ' && str[k] != '\0'; j++, k++) {
            array[i][j] = str[k];
        }
        array[i][j] = '\0';
    }
    array[i] = NULL;
    return (array);
}

char *make_str_line(stru_t *stru)
{
    size_t len;
    char *lineptr = NULL;

    if (getline(&lineptr, &len, stdin) == -1) {
        my_putstr("exit\n");
        free_all(stru);
        quit;
    }
    lineptr = clean_str(lineptr);
    return (lineptr);
}

void get_line(stru_t *stru)
{
    if (stru->nb == 0) {
        stru->str_line = make_str_line(stru);
        stru->tmp = make_double_array_tmp(stru->str_line);
        clean_to_array(stru);
    } if (stru->tmp[stru->nb] == NULL) {
        stru->nb = 0;
        mysh(stru);
    }
    stru->line = make_double_array_line(stru->tmp[stru->nb]);
}